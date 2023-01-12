/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 13:02:59 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_end_test(char **map, int y, int x)
{
	if (map[y][x] == '2')
		return (0);
	if (map[y][x] == 'E' || map[y][x] == 'P' || map[y][x] == 'C')
		map[y][x] = '2';
	if (map[y][x] >= 53)
		return (0);
	if (map[y][x] != '1')
	{
		map[y][x] += 5;
		if (map[y][x + 1] != '1')
			ft_end_test(map, y, x + 1);
		if (map[y][x - 1] != '1')
			ft_end_test(map, y, x - 1);
		if (map[y - 1][x] != '1')
			ft_end_test(map, y - 1, x);
		if (map[y + 1][x] != '1')
			ft_end_test(map, y + 1, x);
	}
	return (0);
}

int	ft_path_valid(t_map *map)
{
	ft_end_test(map->map, map->start_y, map->start_x);
	return (0);
}
