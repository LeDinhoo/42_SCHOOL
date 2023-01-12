/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:19:42 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 12:54:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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

int	ft_map_end_y(char **map)
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
			if (map[y][x] == 'E')
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

int	ft_map_end_x(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == 'E')
			return (x);
		x++;
	}
	return (0);
}

int	ft_map_info(t_map *map)
{
	map->start_y = ft_map_start_y(map->map);
	map->end_y = ft_map_end_y(map->map);
	map->start_x = ft_map_start_x(map->map[map->start_y]);
	map->end_x = ft_map_end_x(map->map[map->end_y]);
	return (0);
}
