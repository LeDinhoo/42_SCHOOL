/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/11 17:50:38 by hdupuy           ###   ########.fr       */
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

int	ft_path_valid(char **map)
{
	int	x;
	int	y;
	int	found;
	int	obj;
	int	b_obj;

	y = ft_map_start_y(map);
	x = ft_map_start_x(map[y]);
	found = 0;
	obj = 0;
	b_obj = 6;
	found = ft_end_test(map, y, x, found);
	return (0);
}
