/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:21:41 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/14 17:42:25 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	join_cmd(t_pip *pipex, char *cmd)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		pipex->path[i] = join_path(pipex->path[i], "/");
		i++;
	}
	i = 0;
	while (pipex->path[i])
	{
		pipex->path[i] = join_path(pipex->path[i], cmd);
		i++;
	}
}

bool	access_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		if (access(pipex->path[i], F_OK | X_OK) == 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

void	remove_cmd(t_pip *pipex, char *cmd)
{
	int	i;
	int	len;
	int	len_path;

	i = 0;
	while (pipex->path[i])
	{
		len = ft_strlen(cmd) + 1;
		len_path = ft_strlen(pipex->path[i]);
		while (len >= 0)
		{
			pipex->path[i][len_path] = '\0';
			len_path--;
			len--;
		}
		i++;
	}
}

void	false_cmd_free(t_pip *pipex, int i)
{
	free(pipex->tab.cmd_args[i][0]);
	pipex->tab.cmd_args[i][0] = NULL;
	ft_printf("%s", pipex->tab.cmd[i]);
	ft_printf(": command not found");
}

bool	process_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab.cmd[i])
	{
		if (pipex->tab.cmd[i][0] == '/' || (pipex->tab.cmd[i][0] == '.'
				&& pipex->tab.cmd[i][1] == '/'))
		{
			if (access(pipex->tab.cmd[i], F_OK | X_OK) == 0)
				return (true);
			else
			{
				false_cmd_free(pipex, i);
				return (false);
			}
		}
		join_cmd(pipex, pipex->tab.cmd[i]);
		if (!access_cmd(pipex))
			return (false);
		remove_cmd(pipex, pipex->tab.cmd[i]);
		i++;
	}
	return (true);
}
