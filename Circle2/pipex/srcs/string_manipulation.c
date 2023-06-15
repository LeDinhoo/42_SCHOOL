/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:06:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:08:30 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	remove_cmd(t_pip *pipex, char *cmd)
{
	int	i;
	int	len;
	int	len_path;

	i = 0;
	while (pipex->path[i])
	{
		len = ft_strlen(cmd) + 1;
		len_path = ft_strlen(pipex->path[i]);
		while (len >= 0)
		{
			pipex->path[i][len_path] = '\0';
			len_path--;
			len--;
		}
		i++;
	}
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

int	search_substring(const char *string, const char *substring)
{
	const char	*s;
	const char	*sub;
	const char	*temp;

	s = string;
	sub = substring;
	if (*s)
	{
		if (*s == *sub)
		{
			temp = s;
			while (*temp && *sub && *temp == *sub)
			{
				temp++;
				sub++;
			}
			if (!*sub)
			{
				return (s - string);
			}
			sub = substring;
		}
	}
	return (-1);
}
