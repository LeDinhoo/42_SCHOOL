/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:57:16 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/03 17:55:56 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_save(char *buff, char *tmp, size_t start)
{
	size_t	index;

	index = 0;
	if (!tmp)
		return (free(tmp));
	while (tmp[start + index] != '\0')
	{
		buff[index] = tmp[start + index];
		index++;
	}
	buff[index] = '\0';
}

int	ft_malloc_size(char *tmp)
{
	size_t	len;

	len = 0;
	while (tmp[len] && tmp[len] != '\n')
		len++;
	if (tmp[len] == '\n')
		return (len + 2);
	else
		return (len + 1);
}

char	*ft_return_line(char *tmp, char *buff)
{
	ssize_t	idx;
	size_t	len;
	char	*r_line;

	len = 0;
	if (tmp[0] == '\0')
		return (free(tmp), NULL);
	r_line = malloc(sizeof(char) * ft_malloc_size(tmp));
	if (!r_line)
		return (free(r_line), free(tmp), NULL);
	idx = -1;
	while (tmp[++idx] && tmp[idx] != '\n')
		r_line[idx] = tmp[idx];
	r_line[idx] = tmp[idx];
	if (tmp[idx++] != '\0')
		ft_new_save(buff, tmp, idx);
	idx--;
	if (tmp[idx] == '\n')
	{
		r_line[idx] = tmp[idx];
		idx++;
	}
	r_line[idx] = '\0';
	free(tmp);
	return (r_line);
}

char	*ft_cpy_save(char *buff, int fd)
{
	int		nb_char;
	char	*tmp;

	nb_char = read(fd, 0, 0);
	if (buff)
	{
		tmp = ft_strjoin(NULL, buff);
		if (!tmp)
			return (free(tmp), NULL);
	}
	nb_char = 1;
	while (nb_char > 0 && ft_strichr(buff, '\n') == -1)
	{
		nb_char = read(fd, buff, BUFFER_SIZE);
		if (nb_char == -1)
			return (free(tmp), free(buff), NULL);
		buff[nb_char] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (tmp == NULL)
			return (free(tmp), NULL);
	}
	return (ft_return_line(tmp, buff));
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
	{
		buff[0] = '\0';
		return (NULL);
	}
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	return (ft_cpy_save(buff, fd));
}

char	**ft_fill_map(int fd, char **map, int count)
{
	int		x;
	char	*line;

	x = 0;
	while (x < count)
	{
		line = get_next_line(fd);
		map[x] = line;
		free(line);
		printf("%s", map[x]);
		x++;
	}
	return (map);
}

#include <string.h>

int	main()
{
	int		fd;
	int		count;
	char	**map;
	char	*tmp;

	fd = open("maps/test.ber", O_RDONLY);
	count = 0;
	while (read(fd, NULL, BUFFER_SIZE) != 0)
	{
		tmp = get_next_line(fd);
		free(tmp);
		count++;
	}
	close(fd);
	map = malloc(sizeof(char *) * (count + 1));
	map[count + 1] = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	map = ft_fill_map(fd, map, count);
	free(map);
}
