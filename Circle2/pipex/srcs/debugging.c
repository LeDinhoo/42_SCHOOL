/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:20 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/21 17:43:16 by hdupuy           ###   ########.fr       */
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

void	print_cmd_args(t_pip *pip)
{
	const t_cmd_list	*current;
	int					i;

	current = pip->cmd_lst;
	while (current != NULL)
	{
		printf("Command: %s\n", current->cmd);
		printf("Command Path: %s\n", current->cmd_path);
		printf("Arguments:\n");
		i = 0;
		while (current->args[i])
		{
			printf("%s\n", current->args[i]);
			i++;
		}
		printf("\n");
		current = current->next;
	}
}
