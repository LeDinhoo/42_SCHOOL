/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:18:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 10:03:42 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_path_cmd(t_pip *pipex, int i)
{
	if (!access(pipex->tab.cmd[i], F_OK | X_OK) == 0)
		free_false_cmd(pipex, i);
	else
		add_cmd_to_path(pipex, pipex->tab.cmd[i]);
}

void	classic_cmd(t_pip *pipex, int i)
{
	if (!pipex->tab.cmd[i])
		free_false_cmd(pipex, i);
	else
	{
		join_cmd(pipex, pipex->tab.cmd[i]);
		if (!access_cmd(pipex))
			free_false_cmd(pipex, i);
		remove_cmd(pipex, pipex->tab.cmd[i]);
	}
}

void	process_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab.cmd[i])
	{
		if (pipex->tab.cmd[i][0] == '\0')
			free_false_cmd(pipex, i);
		else if (pipex->tab.cmd[i][0] == '/' || (pipex->tab.cmd[i][0] == '.'
				&& pipex->tab.cmd[i][1] == '/'))
			full_path_cmd(pipex, i);
		else
			classic_cmd(pipex, i);
		i++;
	}
}
