/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:02:33 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:10:42 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_cmd_arguments(char **argv, int argc, t_pip *pipex)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		access_cmd_full(argv[i], pipex, j);
		i++;
		j++;
	}
	pipex->tab.cmd_args[j] = NULL;
}

void	add_cmd_to_path(t_pip *pipex, char *full_path)
{
	static int	cmd;

	pipex->tab.cmd_path[cmd] = ft_strdup(full_path);
	cmd++;
}
