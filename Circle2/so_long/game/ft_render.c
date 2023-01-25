/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:06:10 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/25 13:59:00 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	move_sprite_and_redraw(void *param)
{
	t_program	*p;

	p = (t_program *)param;
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

int	ft_wich_wall(char **map, t_vector pos, t_walls *wall)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	if (pos.y > 0 && pos.x > 0)
	{
		wall->a = map[pos.y - 1][pos.x - 1];
	}
	if (pos.y > 0)
	{
		wall->b = map[pos.y - 1][pos.x];
		wall->c = map[pos.y - 1][pos.x + 1];
	}
	if (pos.x > 0)
		wall->d = map[pos.y][pos.x - 1];
	wall->e = map[pos.y][pos.x + 1];
	if (pos.x > 0 && pos.y < h - 1)
		wall->f = map[pos.y + 1][pos.x - 1];
	if (pos.y > 0 && pos.y < h - 1)
		wall->g = map[pos.y + 1][pos.x];
	if (pos.y < h - 1)
		wall->h = map[pos.y + 1][pos.x + 1];
	return (0);
}

int	ft_init_wall(t_walls *wall)
{
	wall->a = '?';
	wall->b = '?';
	wall->c = '?';
	wall->d = '?';
	wall->e = '?';
	wall->f = '?';
	wall->g = '?';
	wall->h = '?';
	return (0);
}

int	ft_put_wall(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	t_walls wall;

	ft_init_wall(&wall);
	ft_wich_wall(map, pos, &wall);
	if (wall.g == '0' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_03.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.b == '0' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_04.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.h == '0' && wall.e == '1' && wall.g == '1' && wall.d == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_05.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.f == '0' && wall.d == '1' && wall.g == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_06.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.e == '0' && wall.b == '1' && wall.g == '1' && wall.d == '1'
		&& wall.a == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_02.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.d == '0' && wall.b == '1' && wall.g == '1' && wall.e == '1'
		&& wall.h == '1' && wall.a == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_01.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.c == '0' && wall.b == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_08.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.a == '0' && wall.b == '1' && wall.d == '1' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_07.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.a == '0' && wall.b == '0' && wall.d == '0' && wall.e == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_09.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.h == '0' && wall.g == '0' && wall.e == '0' && wall.d == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_10.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.b == '1' && wall.g == '1' && wall.e == '0' && wall.d == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_11.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.g == '1' && wall.a == '0' && wall.b == '0' && wall.c == '0'
		&& wall.d == '0' && wall.e == '0' && wall.f == '0' && wall.h == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_12.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.b == '1' && wall.a == '0' && wall.g == '0' && wall.c == '0'
		&& wall.d == '0' && wall.e == '0' && wall.f == '0' && wall.h == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_13.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.a == '1' && wall.b == '1' && wall.c == '1' && wall.d == '0'
		&& wall.e == '1' && wall.f == '0' && wall.g == '1' && wall.h == '0')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_14.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.a == '0' && wall.b == '1' && wall.c == '0' && wall.d == '1'
		&& wall.e == '0' && wall.f == '1' && wall.g == '1' && wall.h == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_15.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (wall.a == '1' && wall.b == '1' && wall.c == '1' && wall.d == '0'
		&& wall.e == '1' && wall.f == '0' && wall.g == '1' && wall.h == '1')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_16.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else
	{
		ft_put_grass(p, s);
	}
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
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_00.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (r_num % 2 == 0)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_01.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (r_num % 4 == 0)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_02.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (r_num % 15 == 0)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_03.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	if (r_num % 40 == 0)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->grass_07.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	return (0);
}

int	ft_put_floor(t_program *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ref,
		s->floor_00.ref, p->sprite_position.x,
		p->sprite_position.y);
	return (0);
}

int	ft_update_map(t_sprite *s, t_program *p, char **map)
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
			if (map[pos.y][pos.x] != '1')
				ft_put_floor(p, s);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	ft_sprite_map(t_sprite *s, t_program *p, t_map *map)
{
	t_vector	pos;

	pos.y = 0;
	while (map->map[pos.y])
	{
		pos.x = 0;
		while (map->map[pos.y][pos.x])
		{
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
	return (0);
}
