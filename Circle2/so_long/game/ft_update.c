/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/26 09:44:40 by hdupuy           ###   ########.fr       */
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
			if (map[pos.y][pos.x] != '1')
				ft_put_floor(p, s);
			pos.x++;
		}
		pos.y++;
	}
	ft_put_spawn(p, s, pos_p);
	return (0);
}

int	ft_put_grass(t_program *p, t_sprite *s)
{
// 	r_num % 1 == 0 : 100% des nombres entiers
// r_num % 2 == 0 : 50% des nombres entiers (tous les nombres pairs)
// r_num % 3 == 0 : 33.3% des nombres entiers (tous les nombres divisibles par 3)
// r_num % 4 == 0 : 25% des nombres entiers (tous les nombres divisibles par 4)
// r_num % 5 == 0 : 20% des nombres entiers (tous les nombres divisibles par 5)
// r_num % 6 == 0 : 16.6% des nombres entiers (tous les nombres divisibles par 6)
// r_num % 7 == 0 : 14.2% des nombres entiers (tous les nombres divisibles par 7)
// r_num % 8 == 0 : 12.5% des nombres entiers (tous les nombres divisibles par 8)
// r_num % 9 == 0 : 11.1% des nombres entiers (tous les nombres divisibles par 9)
// r_num % 10 == 0 : 10% des nombres entiers (tous les nombres divisibles par 10)

	int	r_num;

	r_num = rand() % 1000;
	printf("%d\n", r_num);
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
		s->spawn_01.ref, p->sprite_position.x,
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
			{
				pos_p.y = pos.y;
				pos_p.x = pos.x;
			}
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
	return (0);
}
