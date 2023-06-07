/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:21:41 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/07 17:35:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_command_arguments(char *cmd1, char *cmd2, t_pip *pipex)
{
	pipex->cmd1_args = ft_split(cmd1, ' ');
	pipex->cmd2_args = ft_split(cmd2, ' ');
}

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
			return (true);
		i++;
	}
	return (false);
}

void	remove_cmd(t_pip *pipex)
{
	int	i;
	int	len;
	int	len_path;

	i = 0;
	while (pipex->path[i])
	{
		len = ft_strlen(pipex->cmd1);
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

bool	process_cmd(t_pip *pipex)
{
	join_cmd(pipex, pipex->cmd1);
	if (!access_cmd(pipex))
		return (false);
	remove_cmd(pipex);
	join_cmd(pipex, pipex->cmd2);
	if (!access_cmd(pipex))
		return (false);
	return (remove_cmd(pipex), true);
}