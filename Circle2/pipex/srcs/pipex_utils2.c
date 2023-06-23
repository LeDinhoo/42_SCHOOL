/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:36:41 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 15:32:37 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_children(t_pip *pip)
{
	t_cmd_list	*current;

	current = pip->cmd_lst;
	while (current != NULL)
	{
		current = current->next;
		wait(NULL);
	}
}

void	handle_single_cmd_case(t_pip *pip)
{
	if (fork() == 0)
		execute_one_cmd(pip);
	wait(NULL);
}

void	iterate_commands(t_pip *pip)
{
	int			pipe_fd[2];
	int			i;
	t_cmd_list	*current;

	i = 0;
	current = pip->cmd_lst;
	while (current)
	{
		// ft_printf("cmd: %s, is_last: %d, i: %d\n", current->cmd,
		// current->is_last, i);
		// while (current->cmd == NULL && current->next)
		// 	current = current->next;
		if (current->is_last == 0)
			pipe(pipe_fd);
		if (fork() == 0)
			execute_cmd(pip, current, pipe_fd, i);
		if (i != 0)
			close(pip->input_fd);
		if (current->is_last == 0)
		{
			close(pipe_fd[1]);
			pip->input_fd = pipe_fd[0];
		}
		current = current->next;
		i++;
	}
}

void	pipex(t_pip *pip)
{
	pip->nb_steps = cmd_numbers(pip->cmd_lst);
	if (is_only(pip) == 0)
		return ;
	set_last_cmd(pip);
	// if (is_only(pip) == 1)
	// {
	// 	handle_single_cmd_case(pip);
	// 	return ;
	// }
	iterate_commands(pip);
	wait_for_children(pip);
}
