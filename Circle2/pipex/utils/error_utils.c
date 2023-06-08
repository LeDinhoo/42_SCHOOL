/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/08 14:23:05 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_structure(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab.cmd_args[i])
	{
		free_arguments(pipex->tab.cmd_args[i]);
		i++;
	}
	free(pipex->tab.cmd_args);
	free_path(pipex);
	i = 0;
	while (pipex->tab.cmd[i])
	{
		free(pipex->tab.cmd[i]);
		i++;
	}
	free(pipex->tab.cmd);
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
