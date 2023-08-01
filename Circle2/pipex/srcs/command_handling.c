/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:02:33 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 17:36:07 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_cmd_arguments(char **argv, int argc, t_pip *pipex)
{
	int	i;
	int	j;

	i = 2;
	if (pipex->is_here_doc == 1)
		i = 3;
	j = 0;
	while (i < argc - 1)
	{
		access_cmd_full(argv[i], pipex, j);
		i++;
		j++;
	}
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
	new_command->is_last = 0;
	new_command->next = NULL;
}
