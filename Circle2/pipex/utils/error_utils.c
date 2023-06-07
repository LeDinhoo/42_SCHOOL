/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/07 17:32:49 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_structure(t_pip *pipex)
{
	free_arguments(pipex->cmd1_args);
	free_arguments(pipex->cmd2_args);
	free_path(pipex);
	free(pipex->cmd1);
	free(pipex->cmd2);
}

void	handle_access_error(t_pip *pipex)
{
	free_structure(pipex);
	perror("Access");
	exit(0);
}

void	handle_open_error(t_pip *pipex)
{
	free_structure(pipex);
	perror("Error");
	exit(0);
}

void	free_arguments(char **args)
{
	int	i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_path(t_pip *pipex)
{
	int	i;

	i = -1;
	if (pipex->path)
		while (pipex->path[++i])
			free(pipex->path[i]);
	free(pipex->path);
}
