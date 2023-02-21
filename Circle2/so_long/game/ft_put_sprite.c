/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 06:57:55 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/21 12:39:45 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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

int	ft_wall_floor(t_program *p, t_sprite *s, char **map, t_vector pos)
{
	if (map[pos.y][pos.x] == '1')
		ft_put_wall(s, p, map, pos);
	if (map[pos.y][pos.x] != '1')
		ft_put_floor(p, s);
	return (0);
}
