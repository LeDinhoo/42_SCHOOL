/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:03:15 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/20 17:03:54 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->wall = ft_new_sprite(prog->mlx, "./sprite/ground.xpm");
	sprite->wall_01 = ft_new_sprite(prog->mlx, "./sprite/Tile_01.xpm");
	sprite->wall_02 = ft_new_sprite(prog->mlx, "./sprite/Tile_02.xpm");
	sprite->wall_03 = ft_new_sprite(prog->mlx, "./sprite/Tile_03.xpm");
	sprite->wall_04 = ft_new_sprite(prog->mlx, "./sprite/Tile_04.xpm");
	sprite->wall_05 = ft_new_sprite(prog->mlx, "./sprite/Tile_05.xpm");
	sprite->wall_06 = ft_new_sprite(prog->mlx, "./sprite/Tile_06.xpm");
	sprite->wall_07 = ft_new_sprite(prog->mlx, "./sprite/Tile_07.xpm");
	sprite->wall_08 = ft_new_sprite(prog->mlx, "./sprite/Tile_08.xpm");
	sprite->wall_09 = ft_new_sprite(prog->mlx, "./sprite/Tile_09.xpm");
	sprite->wall_10 = ft_new_sprite(prog->mlx, "./sprite/Tile_10.xpm");
	sprite->wall_11 = ft_new_sprite(prog->mlx, "./sprite/Tile_11.xpm");
	sprite->wall_12 = ft_new_sprite(prog->mlx, "./sprite/Tile_12.xpm");
	sprite->wall_13 = ft_new_sprite(prog->mlx, "./sprite/Tile_13.xpm");
	sprite->wall_14 = ft_new_sprite(prog->mlx, "./sprite/Tile_14.xpm");
	sprite->wall_15 = ft_new_sprite(prog->mlx, "./sprite/Tile_15.xpm");
	sprite->floor = ft_new_sprite(prog->mlx, "./sprite/floor.xpm");
	sprite->p_floor = ft_new_sprite(prog->mlx, "./sprite/p_floor.xpm");
	p->py = ft_new_sprite(prog->mlx, "./sprite/player.xpm");
	return (0);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}
