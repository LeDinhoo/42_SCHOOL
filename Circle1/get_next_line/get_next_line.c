/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:57:16 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/25 12:19:53 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_new_save(char *buff, char *tmp, size_t start)
{
	size_t	index;

	index = 0;
	while (tmp[start + index] != '\0')
	{
		buff[index] = tmp[start + index];
		index++;
	}
	while (buff[index])
		buff[index] = '\0';
}

char	*ft_return_line(char *tmp, char *buff)
{
	size_t	idx;
	size_t	len;
	char	*r_line;

	idx = 0;
	len = 0;
	if (tmp[0] == '\0')
		return (free(tmp), NULL);
	while (tmp[len] && tmp[len] != '\n')
		++len;
	r_line = malloc(sizeof(char) * (len + 2));
	while (tmp[idx] && tmp[idx] != '\n')
	{
		r_line[idx] = tmp[idx];
		idx++;
	}
	if (tmp[idx] == '\n')
	{
		r_line[idx] = tmp[idx];
		idx++;
	}
	r_line[idx] = '\0';
	ft_new_save(buff, tmp, idx);
	return (free(tmp), r_line);
}

char	*ft_cpy_save(char *buff, int fd)
{
	int		nb_char;
	char	*tmp;

	tmp = NULL;
	nb_char = 1;
	if (buff)
		tmp = ft_strjoin(tmp, buff);
	while (nb_char > 0 && ft_strichr(buff, '\n') == -1)
	{
		nb_char = read(fd, buff, BUFFER_SIZE);
		if (nb_char == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[nb_char] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	return (ft_return_line(tmp, buff));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = ft_cpy_save(buff, fd);
	if (!line)
		return (NULL);
	return (line);
}
