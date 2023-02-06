/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/31 07:22:07 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_end_test(t_map *map, int y, int x)
{
	int	columns;
	int	rows;

	columns = map->width;
	rows = map->height;
	if (y < 0 || y >= rows || x < 0 || x >= columns)
		return (0);
	if (map->map[y][x] == '2')
		return (0);
	if (map->map[y][x] == 'E' || map->map[y][x] == 'P' || map->map[y][x] == 'C')
		map->map[y][x] = '2';
	if (map->map[y][x] >= 53)
		return (0);
	if (map->map[y][x] != '1')
	{
		map->map[y][x] += 5;
		ft_end_test(map, y, x + 1);
		ft_end_test(map, y, x - 1);
		ft_end_test(map, y - 1, x);
		ft_end_test(map, y + 1, x);
	}
	return (0);
}

int	ft_path_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (ft_strichr("0157\0", map[y][x]) == -1)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_map_reset(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] == '5')
				map->map[y][x] = '0';
			if (map->map[y][x] == '7')
				map->map[y][x] = 'C';
			x++;
		}
		x = 0;
		y++;
	}
	map->map[map->start_y][map->start_x] = 'P';
	map->map[map->end_y][map->end_x] = 'E';
	return (0);
}

int	ft_path_valid(t_map *map)
{
	ft_end_test(map, map->start_y, map->start_x);
	if (ft_path_check(map->map))
	{
		ft_map_reset(map);
		return (1);
	}
	return (0);
}
