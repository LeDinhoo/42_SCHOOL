/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 10:26:34 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	handle_arguments_error(int argc, char **envp)
{
	if (argc < 5)
	{
		write(1, "Error: Not enough arguments\n", 29);
		return (false);
	}
	if (!envp)
	{
		ft_printf("Error: Environment not available");
		return (false);
	}
	return (true);
}

void	exit_fd(t_pip *pip, int pipe_fd[2])
{
	close(pip->f2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free_structure(pip);
	free_cmd_list(pip->cmd_lst);
	exit(1);
}

void	exit_cmd_null(t_pip *pip, int pipe_fd[2])
{
	perror("pipex");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(pip->f2);
	free_structure(pip);
	free_cmd_list(pip->cmd_lst);
	exit(1);
}
