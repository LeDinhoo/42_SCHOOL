/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 14:27:31 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_path_test(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		if (ft_path_test(map, y, x + 1))
			return (1);
		if (ft_path_test(map, y + 1, x))
			return (1);
		if (ft_path_test(map, y, x - 1))
			return (1);
		if (ft_path_test(map, y - 1, x))
			return (1);
	}
	return (0);
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

	y = ft_map_start_y(map);
	x = ft_map_start_x(map[y]);
	if (ft_path_test(map, y, x))
	{
		printf("Le chemin est valide !");
		return (1);
	}
	else
		printf("Le chemin n'est pas valide !");
	return (0);
}
