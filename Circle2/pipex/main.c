/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:33:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_structure(int argc, char **argv, char **envp, t_pip *pipex)
{
	int	i;

	i = 0;
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->tab.cmd = ft_calloc(sizeof(char *), argc - 2);
	pipex->tab.cmd_args = ft_calloc(sizeof(char **), argc - 2);
	pipex->tab.cmd_path = ft_calloc(sizeof(char *), argc - 2);
	get_path(envp, pipex);
	split_cmd_arguments(argv, argc, pipex);
	while (i < argc - 3)
	{
		pipex->tab.cmd[i] = ft_strdup(pipex->tab.cmd_args[i][0]);
		i++;
	}
	pipex->tab.cmd[i] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pipex;

	if (argc < 5)
	{
		ft_printf("Not enough arguments");
		return (1);
	}
	if (!envp)
	{
		ft_printf("Envp not available");
		return (1);
	}
	initialize_structure(argc, argv, envp, &pipex);
	process_cmd(&pipex);
	if (!open_fd(pipex.infile, pipex.outfile, &pipex))
		handle_open_error(&pipex);
	print_args(&pipex);
	free_structure(&pipex);
	return (0);
}
