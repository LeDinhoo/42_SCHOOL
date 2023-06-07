/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/07 17:35:15 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_structure(int argc, char **argv, char **envp, t_pip *pipex)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	get_path(envp, pipex);
	split_command_arguments(argv[2], argv[3], pipex);
	pipex->cmd1 = ft_strdup(pipex->cmd1_args[0]);
	pipex->cmd2 = ft_strdup(pipex->cmd2_args[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pipex;

	if (argc != 5)
		return (1);
	initialize_structure(argc, argv, envp, &pipex);
	if (!process_cmd(&pipex))
		handle_access_error(&pipex);
	if (!open_fd(pipex.infile, pipex.outfile, &pipex))
		handle_open_error(&pipex);
	free_structure(&pipex);
	return (0);
}
