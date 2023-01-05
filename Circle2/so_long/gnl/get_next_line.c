/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:57:16 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 18:19:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*get_line(int fd, char *line, char *buffer, int i)
{
	int	j;

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	while (read(fd, buffer + i, 1) > 0 && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	if (line != NULL)
	{
		j = 0;
		while (j < i)
		{
			line[j] = buffer[j];
			j++;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	line = get_line(fd, line, buffer, 0);
	return (line);
}
