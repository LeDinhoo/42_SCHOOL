/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:02:03 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/26 09:46:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	move_sprite_and_redraw(void *param)
{
	t_program	*p;

	p = (t_program *)param;
	usleep(1000000 / 60);
	if (!ft_check_right(p))
		p->player.x_dir = 0;
	else if (!ft_check_left(p))
		p->player.x_dir = 0;
	else if (!ft_check_up(p))
		p->player.y_dir = 0;
	else if (!ft_check_down(p))
		p->player.y_dir = 0;
	else
	{
		p->player.pos.x += (p->player.x_dir * p->move_speed);
		p->player.pos.y += (p->player.y_dir * p->move_speed);
	}
	if (p->player.x_dir != 0 || p->player.y_dir != 0)
	{
		ft_update_map(&p->sprite, p, p->map);
		mlx_put_image_to_window(p->mlx, p->window.ref, p->player.py.ref,
			p->player.pos.x, p->player.pos.y);
	}
	return (0);
}

int	ft_release(int key, void *param)
{
	t_program	*p;

	p = (t_program *)param;
	if (key == 100)
		p->player.x_dir = 0;
	if (key == 119)
		p->player.y_dir = 0;
	if (key == 115)
		p->player.y_dir = 0;
	if (key == 97)
		p->player.x_dir = 0;
	return (0);
}
