/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:03:35 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/08 16:33:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_command_access(char *command, t_pip *pipex, int index)
{
	char	**cmd_name;

	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
	{
		cmd_name = ft_split(command, ' ');
		if (access(cmd_name[0], F_OK | X_OK) == 0)
		{
			pipex->tab.cmd_args[index] = cmd_name;
		}
	}
	else
	{
		pipex->tab.cmd_args[index] = ft_split(command, ' ');
	}
}

void	split_command_arguments(char **argv, int argc, t_pip *pipex)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		check_command_access(argv[i], pipex, j);
		i++;
		j++;
	}
	pipex->tab.cmd_args[j] = NULL;
}
