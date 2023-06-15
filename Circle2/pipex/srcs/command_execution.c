/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:18:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:27:22 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab.cmd[i])
	{
		if (pipex->tab.cmd[i][0] == '/' || (pipex->tab.cmd[i][0] == '.'
				&& pipex->tab.cmd[i][1] == '/'))
		{
			if (!access(pipex->tab.cmd[i], F_OK | X_OK) == 0)
				free_false_cmd(pipex, i);
			else
				add_cmd_to_path(pipex, pipex->tab.cmd[i]);
		}
		else
		{
			join_cmd(pipex, pipex->tab.cmd[i]);
			if (!access_cmd(pipex))
				free_false_cmd(pipex, i);
			remove_cmd(pipex, pipex->tab.cmd[i]);
		}
		i++;
	}
}
