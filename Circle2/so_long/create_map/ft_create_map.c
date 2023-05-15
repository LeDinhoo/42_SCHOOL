/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/15 15:56:42 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**ft_fill_map(int fd, ssize_t nb_line, char **map)
{
	int		y;

	y = 0;
	map = malloc(sizeof(char *) * nb_line + 1);
	if (!map)
		return (free(map), NULL);
	while (nb_line > 0)
	{
		nb_line--;
		map[y] = NULL;
		map[y] = get_next_line(fd);
		y++;
	}
	return (map);
}

int	ft_number_lines(int fd)
{
	int		count;
	char	c;

	count = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

char	**ft_create_map(t_map *map)
{
	int			fd;

	map->map = NULL;
	fd = open(map->file, O_RDONLY);
	map->height = ft_number_lines(fd) + 1;
	close(fd);
	fd = open(map->file, O_RDONLY);
	map->map = ft_fill_map(fd, map->height, map->map);
	close(fd);
	return (0);
}
