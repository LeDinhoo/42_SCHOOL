/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:24:58 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/26 10:27:04 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_put_wall(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	if (put_wall_1(s, p, map, pos))
		return (1);
	if (put_wall_2(s, p, map, pos))
		return (1);
	if (put_wall_3(s, p, map, pos))
		return (1);
	if (put_wall_4(s, p, map, pos))
		return (1);
	if (put_wall_5(s, p, map, pos))
		return (1);
	if (put_wall_6(s, p, map, pos))
		return (1);
	if (put_wall_7(s, p, map, pos))
		return (1);
	if (put_wall_8(s, p, map, pos))
		return (1);
	ft_put_grass(p, s);
	return (0);
}

int	put_wall_1(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.g == '0' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_03.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.b == '0' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_04.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_2(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.h == '0' && wall.e == '1' && wall.g == '1' && wall.d == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_05.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.f == '0' && wall.d == '1' && wall.g == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_06.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_3(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.e == '0' && wall.b == '1' && wall.g == '1' && wall.d == '1'
		&& wall.a == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_02.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.d == '0' && wall.b == '1' && wall.g == '1' && wall.e == '1'
		&& wall.h == '1' && wall.a == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_01.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}

int	put_wall_4(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls	wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.c == '0' && wall.b == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_08.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	else if (wall.a == '0' && wall.b == '1' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_07.ref, p->sprite_position.x,
			p->sprite_position.y);
		return (1);
	}
	return (0);
}
