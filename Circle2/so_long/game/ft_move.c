/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/20 12:14:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_right(t_vector *pos, char **map)
{
	if ((map[(pos->y) / 40][(pos->x + 31) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_left(t_vector *pos, char **map)
{
	if ((map[(pos->y) / 40][(pos->x - 2) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_up(t_vector *pos, char **map)
{
	if ((map[(pos->y - 2) / 40][(pos->x) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_down(t_vector *pos, char **map)
{
	if ((map[(pos->y + 31) / 40][(pos->x) / 40]) == '1')
		return (0);
	return (1);
}

int key_press(int key, void *param)
{
	t_program	*p;

	p = (t_program *)param;
	if (key == 65363)
		if (ft_check_right(&p->player.pos, p->map))
				p->player.x_dir = 1;
	if (key == 65362)
		if (ft_check_up(&p->player.pos, p->map))
			p->player.y_dir = -1;
	if (key == 65364)
		if (ft_check_down(&p->player.pos, p->map))
			p->player.y_dir = 1;
	if (key == 65361)
		if (ft_check_left(&p->player.pos, p->map))
			p->player.x_dir = -1;
	// printf("%d\n", p->player.x_dir);
	return (0);
}
