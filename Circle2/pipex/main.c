/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/29 13:28:04 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *s1, char *s2)
{
	size_t	index;
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (s1 && s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	len = 0;
	while (s2 && s2[len])
	{
		result[index + len] = s2[len];
		len++;
	}
	result[index + len] = '\0';
	free(s1);
	return (result);
}

void	join_cmd(t_pip *pipex, char *cmd)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		pipex->path[i] = join_path(pipex->path[i], "/");
		i++;
	}
	i = 0;
	while (pipex->path[i])
	{
		pipex->path[i] = join_path(pipex->path[i], cmd);
		i++;
	}
}

bool	access_cmd(t_pip *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		if (access(pipex->path[i], F_OK | X_OK) == 0)
			return (true);
		i++;
	}
	return (false);
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

bool	process_cmd(t_pip *pipex)
{
	join_cmd(pipex, pipex->cmd1);
	if (!access_cmd(pipex))
		return (free_path(pipex), false);
	free_path(pipex);
	join_cmd(pipex, pipex->cmd2);
	if (!access_cmd(pipex))
		return (free_path(pipex), false);
	return (free_path(pipex), true);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pip	pipex;

	i = -1;
	if (argc != 5)
		return (1);
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	get_path(envp, &pipex);
	if (!process_cmd(&pipex))
	{
		ft_printf("Command not found !\n");
		return (0);
	}
	argv[i] = NULL;
	return (0);
}
