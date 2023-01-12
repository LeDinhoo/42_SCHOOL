/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 11:10:31 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_end_test(char **map, int y, int x, int found)
{
	if (found == 1)
		return (1);
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == 'V')
		return (0);
	if (map[y][x] != 1 || map[y][x] != 'E')
	{
		map[y][x] = 'V';
		if (map[y][x + 1] != '1')
			found = ft_end_test(map, y, x + 1, found);
		if (map[y][x - 1] != '1')
			found = ft_end_test(map, y, x - 1, found);
		if (map[y - 1][x] != '1')
			found = ft_end_test(map, y - 1, x, found);
		if (map[y + 1][x] != '1')
			found = ft_end_test(map, y + 1, x, found);
	}
	return (found);
}

int	ft_map_start_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!map)
		return (0);
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_map_start_x(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == 'P')
			return (x);
		x++;
	}
	return (0);
}

int	ft_count_objs(char **map)
{
	int		y;
	int		x;
	int		count;
	char	c;


	y = 0;
	x = 0;
	count = 0;
	c = 'C';
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int	ft_path_valid(t_map *map)
{
	int	found;

	map->start_y = ft_map_start_y(map->map);
	map->start_x = ft_map_start_x(map->map[map->start_y]);
	map->objs = ft_count_objs(map->map);
	found = 0;
	found = ft_end_test(map->map, map->start_y, map->start_x, found);
	if (found == 1)
		printf("OK\n");
	return (0);
}
