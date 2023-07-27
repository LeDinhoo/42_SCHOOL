/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:34:04 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/04 12:36:41 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_numbers(t_cmd_list *cmd)
{
	t_cmd_list	*current;
	int			nb;

	current = cmd;
	nb = 0;
	while (current != NULL)
	{
		current = current->next;
		nb++;
	}
	return (nb);
}

void	set_last_cmd(t_pip *pip)
{
	t_cmd_list	*current;
	t_cmd_list	*last;

	current = pip->cmd_lst;
	while (current)
	{
		last = current;
		current = current->next;
	}
	last->is_last = 1;
}

int	is_only(t_pip *pip)
{
	t_cmd_list	*current;
	int			i;

	i = 0;
	current = pip->cmd_lst;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	execute_one_cmd(t_pip *pip)
{
	t_cmd_list	*current;

	current = pip->cmd_lst;
	dup2(pip->f1, STDIN_FILENO);
	dup2(pip->f2, STDOUT_FILENO);
	while (current->cmd == NULL)
		current = current->next;
	execve(current->cmd_path, current->args, NULL);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	execute_cmd(t_pip *pip, t_cmd_list *current, int pipe_fd[2], int i)
{
	handle_stdin(i, pip);
	if (current->is_last == 1)
		dup2(pip->f2, STDOUT_FILENO);
	if (i != 0)
	{
		if (pip->input_fd != 0)
			dup2(pip->input_fd, STDIN_FILENO);
		close(pip->input_fd);
	}
	if (current->is_last == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (current->cmd)
		execve(current->cmd_path, current->args, NULL);
	else
	{
		perror("pipex");
		free_structure(pip);
		free_cmd_list(pip->cmd_lst);
		exit(EXIT_FAILURE);
	}
}
