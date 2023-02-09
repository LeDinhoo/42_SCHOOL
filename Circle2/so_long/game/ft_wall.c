/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:06:10 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/07 04:19:08 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	put_wall_5(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.a == '0' && wall.b == '0' && wall.d == '0' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_09.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.h == '0' && wall.g == '0' && wall.e == '0' && wall.d == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_10.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_6(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.b == '1' && wall.g == '1' && wall.e == '0' && wall.d == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_11.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.g == '1' && wall.a == '0' && wall.b == '0' && wall.c == '0'
		&& wall.d == '0' && wall.e == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_12.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_7(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.b == '1' && wall.a == '0' && wall.g == '0' && wall.c == '0'
		&& wall.d == '0' && wall.e == '0' && wall.f == '0' && wall.h == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_13.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.a == '1' && wall.b == '1' && wall.c == '1' && wall.d == '0'
		&& wall.e == '1' && wall.f == '0' && wall.g == '1' && wall.h == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_14.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_8(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.a == '0' && wall.b == '1' && wall.c == '0' && wall.d == '1'
		&& wall.e == '0' && wall.f == '1' && wall.g == '1' && wall.h == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_15.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.a == '1' && wall.b == '1' && wall.c == '1' && wall.d == '0'
		&& wall.e == '1' && wall.f == '0' && wall.g == '1' && wall.h == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_16.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}
