/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/20 14:03:43 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
