/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:08 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/10 17:34:17 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_path_test(char **map, int y, int x, int c, int cpt)
{
	int	found;

	if (c + 1 == cpt)
		return (1);
	if (map[y][x] == 'E' || map[y][x] == 'C')
	{
		cpt++;
		printf("%d\n", c);
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	map[y][x] = 'V';
	found = ft_path_test(map, y, x + 1, c, cpt);
	found = ft_path_test(map, y, x - 1, c, cpt);
	found = ft_path_test(map, y + 1, x, c, cpt);
	found = ft_path_test(map, y - 1, x, c, cpt);
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

	y = ft_map_start_y(map);
	x = ft_map_start_x(map[y]);
	int c = 6;
	int cpt = 0;
	if (ft_path_test(map, y, x, c, cpt))
	{
		printf("Le chemin est valide !");
		return (1);
	}
	else
		printf("Le chemin n'est pas valide !");
	return (0);
}
