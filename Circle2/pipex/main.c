/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 10:34:36 by hdupuy           ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;

	if (!handle_arguments_error(argc, envp))
		return (1);
	initialize_structure(argc, argv, envp, &pip);
	open_fd(pip.infile, pip.outfile, &pip);
	process_cmd(&pip);
	add_command(&pip, &pip.cmd_lst);
	pipex(&pip);
	free_structure(&pip);
	free_cmd_list(pip.cmd_lst);
	exit(EXIT_SUCCESS);
	return (0);
}
