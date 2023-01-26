/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:55:46 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/26 09:56:20 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_wich_wall(char **map, t_vector pos, t_walls *wall)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	if (pos.y > 0 && pos.x > 0)
	{
		wall->a = map[pos.y - 1][pos.x - 1];
	}
	if (pos.y > 0)
	{
		wall->b = map[pos.y - 1][pos.x];
		wall->c = map[pos.y - 1][pos.x + 1];
	}
	if (pos.x > 0)
		wall->d = map[pos.y][pos.x - 1];
	wall->e = map[pos.y][pos.x + 1];
	if (pos.x > 0 && pos.y < h - 1)
		wall->f = map[pos.y + 1][pos.x - 1];
	if (pos.y > 0 && pos.y < h - 1)
		wall->g = map[pos.y + 1][pos.x];
	if (pos.y < h - 1)
		wall->h = map[pos.y + 1][pos.x + 1];
	return (0);
}

int	ft_init_wall(t_walls *wall)
{
	wall->a = '?';
	wall->b = '?';
	wall->c = '?';
	wall->d = '?';
	wall->e = '?';
	wall->f = '?';
	wall->g = '?';
	wall->h = '?';
	return (0);
}
