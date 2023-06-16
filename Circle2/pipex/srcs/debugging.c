/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:20 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 09:19:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_args(t_pip *pipex)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (pipex->tab.cmd_args[i])
	{
		ft_printf("Command n°%d\n", i);
		if (pipex->tab.cmd_args[i][0])
		{
			ft_printf("Command Path: %s\n", pipex->tab.cmd_path[k]);
			k++;
		}
		ft_printf("Arguments Tab:\n");
		while (pipex->tab.cmd_args[i][j])
		{
			ft_printf("%s\n", pipex->tab.cmd_args[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}
