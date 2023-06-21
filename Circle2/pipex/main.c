/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/21 18:02:12 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_structure(int argc, char **argv, char **envp, t_pip *pip)
{
	int	i;

	i = 0;
	pip->infile = argv[1];
	pip->outfile = argv[argc - 1];
	pip->tab.cmd = ft_calloc(sizeof(char *), argc - 2);
	pip->tab.cmd_args = ft_calloc(sizeof(char **), argc - 2);
	pip->tab.cmd_path = ft_calloc(sizeof(char *), argc - 2);
	pip->cmd_lst = NULL;
	get_path(envp, pip);
	split_cmd_arguments(argv, argc, pip);
	while (i < argc - 3)
	{
		pip->tab.cmd[i] = ft_strdup(pip->tab.cmd_args[i][0]);
		i++;
	}
	pip->tab.cmd[i] = NULL;
}

void	explain_status(int child_status)
{
	printf("# La commande s'est terminée ");
	if (WIFEXITED(child_status))
	{
		printf("par exit(%d)\n", WEXITSTATUS(child_status));
	}
	else if (WIFSIGNALED(child_status))
	{
		printf("par la réception du signal %d\n", WTERMSIG(child_status));
	}
	else
	{
		printf("pour une raison x ou y.\n");
	}
}

void	first_task(t_pip *pip, int *pipe_fd)
{
	dup2(pip->f1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!pip->tab.cmd_args[0][0])
	{
		free_structure(pip);
	}
	else
		execve(pip->tab.cmd_path[0], pip->tab.cmd_args[0], NULL);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	execute_task(t_pip *pip, int *pipe_fd)
{
	dup2(pip->input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pip->input_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!pip->tab.cmd_args[1][0])
	{
		execve(pip->tab.cmd_path[0], pip->tab.cmd_args[0], NULL);
		free_structure(pip);
	}
	else
		execve(pip->tab.cmd_path[1], pip->tab.cmd_args[1], NULL);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	last_task(t_pip *pip, int *pipe_fd)
{
	dup2(pip->input_fd, STDIN_FILENO);
	dup2(pip->f2, STDOUT_FILENO);
	close(pip->input_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!pip->tab.cmd_args[2][0])
	{
		execve(pip->tab.cmd_path[1], pip->tab.cmd_args[1], NULL);
		free_structure(pip);
	}
	else
		execve(pip->tab.cmd_path[2], pip->tab.cmd_args[2], NULL);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	pipex(t_pip *pip)
{
	int	child_status;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pip->a_pid = fork();
	if (pip->a_pid == 0)
		first_task(pip, pipe_fd);
	close(pipe_fd[1]);
	pip->input_fd = pipe_fd[0];
	// ------------------------//
	pipe(pipe_fd);
	pip->b_pid = fork();
	if (pip->b_pid == 0)
		execute_task(pip, pipe_fd);
	close(pip->input_fd);
	close(pipe_fd[1]);
	pip->input_fd = pipe_fd[0];
	// ------------------------//
	pipe(pipe_fd);
	pip->c_pid = fork();
	if (pip->c_pid == 0)
		last_task(pip, pipe_fd);
	close(pip->input_fd);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	waitpid(pip->a_pid, &child_status, 0);
	waitpid(pip->b_pid, &child_status, 0);
	waitpid(pip->c_pid, &child_status, 0);
	explain_status(child_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;

	if (!handle_arguments_error(argc, envp))
		return (1);
	initialize_structure(argc, argv, envp, &pip);
	open_fd(pip.infile, pip.outfile, &pip);
	process_cmd(&pip);
	add_command(&pip, &pip.cmd_lst);
	// print_cmd_args(&pip);
	// print_args(&pip);
	pipex(&pip);
	free_structure(&pip);
	free_cmd_list(pip.cmd_lst);
	exit(EXIT_SUCCESS);
	return (0);
}
