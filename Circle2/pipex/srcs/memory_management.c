/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:13:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/21 18:01:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_false_cmd(t_pip *pipex, int i)
{
	int	j;

	j = 0;
	while (pipex->tab.cmd_args[i][j])
	{
		free(pipex->tab.cmd_args[i][j]);
		pipex->tab.cmd_args[i][j] = NULL;
		j++;
	}
	ft_printf("%s", pipex->tab.cmd[i]);
	ft_printf(": command not found\n");
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

void	free_cmd_list(t_cmd_list *list)
{
	t_cmd_list	*current;
	t_cmd_list	*next;
	char		**arg;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		if (current->args != NULL)
		{
			arg = current->args;
			while (*arg != NULL)
			{
				free(*arg);
				arg++;
			}
			free(current->args);
		}
		free(current);
		current = next;
	}
}

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
	i = 0;
	while (pipex->tab.cmd_path[i])
	{
		free(pipex->tab.cmd_path[i]);
		i++;
	}
	free(pipex->tab.cmd_path);
}
