/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:10:22 by dupuy             #+#    #+#             */
/*   Updated: 2023/05/17 16:12:44 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	split_path(char *path, t_pip *pipex)
{
	if (path)
		pipex->path = ft_split(path + 5, ':');
	return ;
}

void	get_path(char **env, t_pip *pipex)
{
	int		i;
	char	*path;

	i = -1;
	pipex->path = NULL;
	while (env[++i])
		if (search_substring(env[i], "PATH=") != -1)
			path = env[i];
	split_path(path, pipex);
	return ;
}
