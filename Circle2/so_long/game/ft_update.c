/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/06 11:41:51 by hdupuy           ###   ########.fr       */
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

int	ft_sprite_map(t_sprite *s, t_program *p, t_map *map)
{
	int b = 0;
	while (map->map[b])
	{
		printf("%s\n", map->map[b]);
		b++;
	}
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
			ft_wall_floor(p, s, map->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	ft_put_spawn(p, s, pos_p);
	ft_put_object(s, p, map->map);
	return (0);
}

int	ft_smoke_anim(void *param)
{
	t_program	*p;
	int			frame;
	int			y;
	int			x;

	p = (t_program *)param;
	y = p->player.pos.y - 6;
	x = p->player.pos.x - 42;
	frame = 0;
	while (frame < (FRAMES * 20))
	{
		ft_smoke_anim1(p, y, x, frame);
		ft_smoke_anim2(p, y, x, frame);
		ft_smoke_anim3(p, y, x, frame);
		ft_smoke_anim4(p, y, x, frame);
		ft_smoke_anim5(p, y, x, frame);
		if (frame == FRAMES * 20)
			return (0);
		frame++;
	}
	return (0);
}
