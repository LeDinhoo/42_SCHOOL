/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/14 11:49:05 by hdupuy           ###   ########.fr       */
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

int	ft_game_init(t_program *prog)
{
	prog->g_image_list = NULL;
	prog->move_speed = 3;
	prog->player.pos.y = (prog->map.start_y * 64) - 26;
	prog->player.pos.x = (prog->map.start_x * 64) + 10;
	prog->player.x_dir = 0;
	prog->player.y_dir = 0;
	prog->mlx = mlx_init();
	prog->window = ft_new_window(prog->mlx, (prog->map.width * 64),
			(prog->map.height * 64), "Bonjour !");
	ft_map_start(prog);
	ft_smoke_anim(prog);
	mlx_hook(prog->window.ref, 2, 1L << 0, *key_press, prog);
	mlx_hook(prog->window.ref, 3, 1L << 1, *ft_release, prog);
	mlx_loop_hook(prog->mlx, move_sprite_and_redraw, prog);
	mlx_loop(prog->mlx);
	return (0);
}
