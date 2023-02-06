/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:27:52 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/30 10:03:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_put_object(t_sprite *s, t_program *p, char **map)
{
	t_vector	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			p->sprite_position.x = (pos.x * 64);
			p->sprite_position.y = (pos.y * 64);
			if (map[pos.y][pos.x] == 'C')
				ft_sprite_obj(p, s);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	ft_sprite_obj(t_program *p, t_sprite *s)
{
	static int	frame;

	frame++;
	if (frame < 100000)
	{
		if (frame == 1)
		{
			mlx_put_image_to_window(p->mlx, p->window.ref,
				s->obj_00.ref, p->sprite_position.x,
				p->sprite_position.y);
		}
		if (frame == 10000)
		{
			mlx_put_image_to_window(p->mlx, p->window.ref,
				s->obj_01.ref, p->sprite_position.x,
				p->sprite_position.y);
		}
		ft_sprite_obj2(p, s, frame);
		ft_sprite_obj3(p, s, frame);
		if (frame == 70000)
			frame = 0;
	}
	return (0);
}

int	ft_sprite_obj2(t_program *p, t_sprite *s, int frame)
{
	if (frame == 20000)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->obj_02.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (frame == 30000)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->obj_03.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (frame == 40000)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->obj_04.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	return (0);
}

int	ft_sprite_obj3(t_program *p, t_sprite *s, int frame)
{
	if (frame == 50000)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->obj_05.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (frame == 60000)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->obj_06.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	return (0);
}
