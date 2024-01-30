/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:03 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/30 14:01:32 by hdupuy           ###   ########.fr       */
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

t_cmd_list	*create_new_command(t_pip *pipex, int *k, int i)
{
	t_cmd_list	*new_command;

	new_command = ft_calloc(sizeof(t_cmd_list), 1);
	if (new_command == NULL)
		return (NULL);
	if (pipex->tab.cmd_args[i][0])
	{
		init_new_command(pipex, new_command, *k, i);
		(*k)++;
	}
	return (new_command);
}

void	append_command(t_cmd_list **head, t_cmd_list *new_command)
{
	t_cmd_list	*current;

	if (*head == NULL)
		*head = new_command;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_command;
	}
}

void	add_command(t_pip *pipex, t_cmd_list **head)
{
	int			i;
	int			k;
	t_cmd_list	*new_command;

	i = 0;
	k = 0;
	while (pipex->tab.cmd_args[i])
	{
		new_command = create_new_command(pipex, &k, i);
		if (new_command == NULL)
			return ;
		append_command(head, new_command); 
		i++;
	}
}
