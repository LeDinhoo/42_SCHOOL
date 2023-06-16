/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:03 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 09:23:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_cmd_full(char *command, t_pip *pipex, int index)
{
	char	**cmd_name;

	if (!check_whitespace_only(command))
	{
		pipex->tab.cmd_args[index] = ft_calloc(2, sizeof(char **));
		pipex->tab.cmd_args[index][0] = ft_calloc(2, sizeof(char *));
	}
	else if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
	{
		cmd_name = ft_split(command, ' ');
		pipex->tab.cmd_args[index] = cmd_name;
	}
	else
		pipex->tab.cmd_args[index] = ft_split(command, ' ');
}

bool	access_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		if (access(pipex->path[i], F_OK | X_OK) == 0)
		{
			add_cmd_to_path(pipex, pipex->path[i]);
			return (true);
		}
		i++;
	}
	return (false);
}
