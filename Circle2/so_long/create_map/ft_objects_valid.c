/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:30:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/03/10 12:20:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_unique_object(char **map)
{
	int	y;
	int	x;
	int	e;
	int	p;

	y = 0;
	x = 0;
	e = 0;
	p = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (e != 1 || p != 1)
		return (0);
	return (1);
}

int	ft_count_objs(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
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

int	ft_char_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (ft_strichr("01PCE\0\n", map[y][x]) == -1)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_unique_object(map))
		return (1);
	return (0);
}

int	ft_objects_valid(t_map *map)
{
	map->objs = ft_count_objs(map->map);
	if (map->objs == 0)
	{
		write(1, "Invalid Objects !", 18);
		ft_free_error(map);
	}
	if (ft_char_valid(map->map))
		return (1);
	return (0);
}
