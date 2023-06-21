/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:02:33 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/21 17:52:13 by hdupuy           ###   ########.fr       */
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

int	args_len(t_pip *pip, int i)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (pip->tab.cmd_args[i][j])
	{
		j++;
		len++;
	}
	len++;
	return (len);
}

void	add_cmd_args(t_pip *pip, int i, t_cmd_list *new_cmd)
{
	int	cmd_len;
	int	arg_len;
	int	j;

	j = 0;
	arg_len = args_len(pip, i);
	new_cmd->args = ft_calloc(sizeof(char *), arg_len);
	while (pip->tab.cmd_args[i][j])
	{
		cmd_len = ft_strlen(pip->tab.cmd_args[i][j]);
		new_cmd->args[j] = ft_calloc(sizeof(char), cmd_len + 1);
		new_cmd->args[j] = ft_strcpy(new_cmd->args[j], pip->tab.cmd_args[i][j]);
		j++;
	}
}

void	init_new_command(t_pip *pipex, t_cmd_list *new_command, int k, int i)
{
	new_command->cmd = pipex->tab.cmd_args[i][0];
	new_command->cmd_path = pipex->tab.cmd_path[k];
	add_cmd_args(pipex, i, new_command);
	new_command->next = NULL;
}

void	add_command(t_pip *pipex, t_cmd_list **head)
{
	int			i;
	int			k;
	t_cmd_list	*new_command;
	t_cmd_list	*current;

	i = 0;
	k = 0;
	new_command = NULL;
	current = NULL;
	while (pipex->tab.cmd_args[i])
	{
		new_command = malloc(sizeof(t_cmd_list));
		if (new_command == NULL)
			return ;
		if (pipex->tab.cmd_args[i][0])
		{
			init_new_command(pipex, new_command, k, i);
			k++;
		}
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
		i++;
	}
}
