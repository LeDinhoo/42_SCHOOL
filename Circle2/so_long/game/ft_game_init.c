/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/12 15:37:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_map_start(t_program *prog)
{
	ft_all_sprite(&prog->sprite, prog, &prog->player);
	ft_sprite_map(&prog->sprite, prog, &prog->map);
	mlx_put_image_to_window(prog->mlx, prog->window.ref, prog->player.py.ref,
		prog->player.pos.x, prog->player.pos.y);
	return (0);
}

int	ft_obj_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	ft_destroy_image(t_program *p, void *img_ptr)
{
	if (img_ptr == NULL)
		return ;
	mlx_destroy_image(p->mlx, img_ptr);
}

int	ft_end(t_program *p)
{
	ft_destroy_image(p, p->sprite.floor_00.ref);
	ft_destroy_image(p, p->sprite.p_floor.ref);
	ft_destroy_image(p, p->sprite.grass_00.ref);
	ft_destroy_image(p, p->sprite.grass_01.ref);
	ft_destroy_image(p, p->sprite.grass_02.ref);
	ft_destroy_image(p, p->sprite.grass_03.ref);
	ft_destroy_image(p, p->sprite.grass_04.ref);
	ft_destroy_image(p, p->sprite.grass_05.ref);
	ft_destroy_image(p, p->sprite.grass_07.ref);
	ft_destroy_image(p, p->sprite.spawn.ref);
	ft_destroy_image(p, p->sprite.spawn_01.ref);
	ft_destroy_image(p, p->sprite.obj_00.ref);
	ft_destroy_image(p, p->sprite.obj_01.ref);
	ft_destroy_image(p, p->sprite.obj_02.ref);
	ft_destroy_image(p, p->sprite.obj_03.ref);
	ft_destroy_image(p, p->sprite.obj_04.ref);
	ft_destroy_image(p, p->sprite.obj_05.ref);
	ft_destroy_image(p, p->sprite.obj_06.ref);
	ft_destroy_image(p, p->player.py.ref);
	ft_destroy_image(p, p->sprite.wall_01.ref);
	ft_destroy_image(p, p->sprite.wall_02.ref);
	ft_destroy_image(p, p->sprite.wall_03.ref);
	ft_destroy_image(p, p->sprite.wall_04.ref);
	ft_destroy_image(p, p->sprite.wall_05.ref);
	ft_destroy_image(p, p->sprite.wall_06.ref);
	ft_destroy_image(p, p->sprite.wall_07.ref);
	ft_destroy_image(p, p->sprite.wall_08.ref);
	ft_destroy_image(p, p->sprite.wall_09.ref);
	ft_destroy_image(p, p->sprite.wall_10.ref);
	ft_destroy_image(p, p->sprite.wall_11.ref);
	ft_destroy_image(p, p->sprite.wall_12.ref);
	ft_destroy_image(p, p->sprite.wall_13.ref);
	ft_destroy_image(p, p->sprite.wall_14.ref);
	ft_destroy_image(p, p->sprite.wall_15.ref);
	ft_destroy_image(p, p->sprite.wall_16.ref);
	ft_destroy_image(p, p->sprite.smoke_00.ref);
	ft_destroy_image(p, p->sprite.smoke_01.ref);
	ft_destroy_image(p, p->sprite.smoke_02.ref);
	ft_destroy_image(p, p->sprite.smoke_03.ref);
	ft_destroy_image(p, p->sprite.smoke_04.ref);
	ft_destroy_image(p, p->sprite.smoke_05.ref);
	ft_destroy_image(p, p->sprite.smoke_06.ref);
	ft_destroy_image(p, p->sprite.smoke_07.ref);
	ft_destroy_image(p, p->sprite.smoke_08.ref);
	ft_destroy_image(p, p->sprite.smoke_09.ref);
	ft_destroy_image(p, p->sprite.smoke_10.ref);
	ft_destroy_image(p, p->sprite.smoke_11.ref);
	ft_destroy_image(p, p->sprite.smoke_12.ref);
	ft_destroy_image(p, p->sprite.smoke_13.ref);
	ft_destroy_image(p, p->sprite.smoke_14.ref);
	ft_destroy_image(p, p->sprite.smoke_15.ref);
	ft_destroy_image(p, p->sprite.smoke_16.ref);
	ft_destroy_image(p, p->sprite.smoke_17.ref);
	ft_destroy_image(p, p->sprite.smoke_18.ref);
	ft_destroy_image(p, p->sprite.smoke_19.ref);
	mlx_destroy_display(p->mlx);
	mlx_destroy_window(p->mlx, p->window.ref);
	free(p->mlx);
	return (0);
}

int	ft_finish(t_program *p)
{
	if (p->map.map[(p->player.pos.y + 26) / 64]
		[(p->player.pos.x - 10) / 64] == 'E')
	{
		if (ft_obj_check(p->map.map))
		{
			write(1, "Good game !", 11);
			ft_free(p);
			ft_end(p);
			exit(0);
		}
	}
	return (0);
}

int	ft_game_init(t_program *prog)
{
	prog->move_speed = 3;
	prog->player.pos.y = (prog->map.start_y * 64) - 26;
	prog->player.pos.x = (prog->map.start_x * 64) + 10;
	prog->player.x_dir = 0;
	prog->player.y_dir = 0;
	prog->mlx = mlx_init(); // check not NULL
	prog->window = ft_new_window(prog->mlx, (prog->map.width * 64),
			(prog->map.height * 64), "Bonjour !"); //check not NULL
	ft_map_start(prog);
	ft_smoke_anim(prog);
	mlx_hook(prog->window.ref, 2, 1L << 0, *key_press, prog);
	mlx_hook(prog->window.ref, 3, 1L << 1, *ft_release, prog);
	mlx_loop_hook(prog->mlx, move_sprite_and_redraw, prog);
	mlx_loop(prog->mlx);
	return (0);
}
