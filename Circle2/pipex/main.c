/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/14 17:55:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_structure(int argc, char **argv, char **envp, t_pip *pipex)
{
	int	i;

	i = 0;
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	get_path(envp, pipex);
	split_command_arguments(argv, argc, pipex);
	while (i < argc - 3)
	{
		pipex->tab.cmd[i] = ft_strdup(pipex->tab.cmd_args[i][0]);
		i++;
	}
	pipex->tab.cmd[i] = NULL;
}

void	print_args(t_pip *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pipex->tab.cmd_args[i])
	{
		while (pipex->tab.cmd_args[i][j])
		{
			ft_printf("%s\n", pipex->tab.cmd_args[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}

int	check_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
			return (ft_printf("Error empty arguments", 1));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pipex;

	if (argc < 5)
	{
		ft_printf("Not enough arguments");
		return (1);
	}
	pipex.tab.cmd_args = malloc(sizeof(char **) * argc - 2);
	pipex.tab.cmd = malloc(sizeof(char *) * argc - 2);
	initialize_structure(argc, argv, envp, &pipex);
	// process_cmd(&pipex);
	// print_args(&pipex);
	if (!process_cmd(&pipex))
	{
		print_args(&pipex);
		handle_access_error(&pipex);
	}
	if (!open_fd(pipex.infile, pipex.outfile, &pipex))
		handle_open_error(&pipex);
	free_structure(&pipex);
	return (0);
}
