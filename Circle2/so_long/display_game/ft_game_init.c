/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/19 19:05:33 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

int	ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->wall = ft_new_sprite(prog->mlx, "./display_game/wall.xpm");
	sprite->wall_d = ft_new_sprite(prog->mlx, "./display_game/wall_d.xpm");
	sprite->wall_r = ft_new_sprite(prog->mlx, "./display_game/wall_r.xpm");
	sprite->wall_l = ft_new_sprite(prog->mlx, "./display_game/wall_l.xpm");
	sprite->wall_u = ft_new_sprite(prog->mlx, "./display_game/wall_u.xpm");
	sprite->floor = ft_new_sprite(prog->mlx, "./display_game/floor.xpm");
	sprite->p_floor = ft_new_sprite(prog->mlx, "./display_game/p_floor.xpm");
	p->py = ft_new_sprite(prog->mlx, "./display_game/player.xpm");
	return (0);
}

int	ft_put_wall(t_sprite *s, t_program *p, char **map, t_vector pos)
{
	if (map[pos.y + 1] && (map[pos.y + 1][pos.x] == '0' || map[pos.y + 1][pos.x] == 'P'))
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_d.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (map[pos.y][pos.x + 1] == '0' || map[pos.y][pos.x + 1] == 'P')
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_r.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (pos.y > 0 && (map[pos.y - 1][pos.x] == '0' || map[pos.y - 1][pos.x] == 'P'))
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_u.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else if (pos.x > 0 && (map[pos.y][pos.x - 1] == '0' || map[pos.y][pos.x - 1] == 'P'))
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall_l.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	else
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			s->wall.ref, p->sprite_position.x,
			p->sprite_position.y);
	}
	return (0);
}

int	ft_sprite_map(t_sprite *s, t_program *p, char **map)
{
	t_vector pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
				p->sprite_position.x = (pos.x * 40);
				p->sprite_position.y = (pos.y * 40);
			if (map[pos.y][pos.x] == '1')
				ft_put_wall(s, p, map, pos);
			else
			{
				mlx_put_image_to_window(p->mlx, p->window.ref,
					s->floor.ref, p->sprite_position.x,
					p->sprite_position.y);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int move_sprite_and_redraw(void *param)
{
    t_program *p = (t_program *)param;

	int old_x;
	int old_y;

	old_x = p->player.pos.x;
	old_y = p->player.pos.y;
	p->player.pos.x += (p->player.x_dir * p->move_speed);
	p->player.pos.y += (p->player.y_dir * p->move_speed);
	if (p->player.x_dir != 0 || p->player.y_dir != 0)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.p_floor.ref, old_x, old_y);
		mlx_put_image_to_window(p->mlx, p->window.ref, p->player.py.ref,
			p->player.pos.x, p->player.pos.y);
		p->player.x_dir = 0;
		p->player.y_dir = 0;
	}
	return (0);
}

int	ft_check_right(t_vector *pos, char **map)
{
	if ((map[(pos->y) / 40][(pos->x + 31) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_left(t_vector *pos, char **map)
{
	if ((map[(pos->y) / 40][(pos->x - 2) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_up(t_vector *pos, char **map)
{
	if ((map[(pos->y - 2) / 40][(pos->x) / 40]) == '1')
		return (0);
	return (1);
}

int	ft_check_down(t_vector *pos, char **map)
{
	if ((map[(pos->y + 31) / 40][(pos->x) / 40]) == '1')
		return (0);
	return (1);
}

int key_press(int key, void *param)
{
	t_program *p = (t_program *)param;

	if (key == 65363)
		if (ft_check_right(&p->player.pos, p->map))
				p->player.x_dir = 1;
	if (key == 65362)
		if (ft_check_up(&p->player.pos, p->map))
			p->player.y_dir = -1;
	if (key == 65364)
		if (ft_check_down(&p->player.pos, p->map))
			p->player.y_dir = 1;
	if (key == 65361)
		if (ft_check_left(&p->player.pos, p->map))
			p->player.x_dir = -1;
	// printf("%d\n", p->player.x_dir);
	return (0);
}

int	ft_game_init(t_map *map)
{
	t_program	prog;

	prog.move_speed = 4;
	prog.player.pos.y = map->start_y * 40;
	prog.player.pos.x = map->start_x * 40;
	prog.player.x_dir = 0;
	prog.player.y_dir = 0;
	prog.map = map->map;
	prog.mlx = mlx_init();
	prog.window = ft_new_window(prog.mlx, (map->width * 40),
			(map->height * 40), "Bonjour !");
	ft_all_sprite(&prog.sprite, &prog, &prog.player);
	ft_sprite_map(&prog.sprite, &prog, map->map);
	mlx_hook(prog.window.ref, 2, 1L << 0, *key_press, &prog);
	mlx_loop_hook(prog.mlx, move_sprite_and_redraw, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
