/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/27 14:29:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_update_map(t_sprite *s, t_program *p, char **map)
{
	t_vector	pos;
	t_vector	pos_p;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
			{
				pos_p.y = pos.y;
				pos_p.x = pos.x;
			}
			p->sprite_position.x = (pos.x * 64);
			p->sprite_position.y = (pos.y * 64);
			if (map[pos.y][pos.x] != '1' && map[pos.y][pos.x] != 'C')
				ft_put_floor(p, s);
			pos.x++;
		}
		pos.y++;
	}
	ft_put_spawn(p, s, pos_p);
	return (0);
}

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
	printf("%d\n", frame);
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
		if (frame == 70000)
			frame = 0;
	}
	return (0);
}

int	ft_put_grass(t_program *p, t_sprite *s)
{
	int	r_num;

	r_num = rand() % 1000;
	if (r_num % 1 == 0)
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_00.ref, p->sprite_position.x,
			p->sprite_position.y);
	if (r_num % 2 == 0)
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_01.ref, p->sprite_position.x,
			p->sprite_position.y);
	if (r_num % 4 == 0)
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_02.ref, p->sprite_position.x,
			p->sprite_position.y);
	if (r_num % 15 == 0)
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_03.ref, p->sprite_position.x,
			p->sprite_position.y);
	if (r_num % 40 == 0)
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_07.ref, p->sprite_position.x,
			p->sprite_position.y);
	return (0);
}

int	ft_put_floor(t_program *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ref,
		s->floor_00.ref, p->sprite_position.x,
		p->sprite_position.y);
	return (0);
}

int	ft_put_spawn(t_program *p, t_sprite *s, t_vector pos_p)
{
	p->sprite_position.x = ((pos_p.x * 64) - 32);
	p->sprite_position.y = ((pos_p.y * 64) - 32);
	mlx_put_image_to_window(p->mlx, p->window.ref,
		s->spawn.ref, p->sprite_position.x,
		p->sprite_position.y);
	return (0);
}

int	ft_sprite_map(t_sprite *s, t_program *p, t_map *map)
{
	t_vector	pos;
	t_vector	pos_p;

	pos.y = 0;
	while (map->map[pos.y])
	{
		pos.x = 0;
		while (map->map[pos.y][pos.x])
		{
			if (map->map[pos.y][pos.x] == 'P')
				pos_p = pos;
			p->sprite_position.x = (pos.x * 64);
			p->sprite_position.y = (pos.y * 64);
			if (map->map[pos.y][pos.x] == '1')
				ft_put_wall(s, p, map->map, pos);
			if (map->map[pos.y][pos.x] != '1')
				ft_put_floor(p, s);
			pos.x++;
		}
		pos.y++;
	}
	ft_put_spawn(p, s, pos_p);
	ft_put_object(s, p, map->map);
	return (0);
}
