/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:30:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 18:52:27 by hdupuy           ###   ########.fr       */
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
			if (e > 1 || p > 1)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
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
