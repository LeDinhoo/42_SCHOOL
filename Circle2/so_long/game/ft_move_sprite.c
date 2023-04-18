/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:02:03 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/18 10:22:36 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	move_sprite_and_redraw(void *param)
{
	t_program	*p;
	static int	frame;

	p = (t_program *)param;
	frame++;
	ft_put_object(&p->sprite, p, p->map.map);
	if (frame % 1000 == 0)
	{
		ft_check_all(p);
		ft_finish(p);
		frame = 0;
	}
	return (0);
}

int	ft_check_all(t_program *p)
{
	static int	i;

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
		i++;
		ft_printf("%d\n", i);
		ft_update_map(&p->sprite, p, p->map.map);
		mlx_put_image_to_window(p->mlx, p->window.ref, p->player.py.ref,
			p->player.pos.x, p->player.pos.y);
	}
	return (0);
}

int	ft_stop(t_program *p)
{
	ft_end(p);
	exit(0);
}

int	key_press(int key, void *param)
{
	t_program	*p;

	p = (t_program *)param;
	if (key == 65307)
		ft_stop(p);
	if (key == 100)
		p->player.x_dir = 1;
	if (key == 119)
		p->player.y_dir = -1;
	if (key == 115)
		p->player.y_dir = 1;
	if (key == 97)
		p->player.x_dir = -1;
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
