/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:03:15 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/25 13:19:24 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->spawn = ft_new_sprite(prog->mlx, "./sprite/Spawn.xpm");
	sprite->wall = ft_new_sprite(prog->mlx, "./sprite/Grass_01.xpm");
	sprite->wall_01 = ft_new_sprite(prog->mlx, "./sprite/Wall_05.xpm");
	sprite->wall_02 = ft_new_sprite(prog->mlx, "./sprite/Wall_0.xpm");
	sprite->wall_03 = ft_new_sprite(prog->mlx, "./sprite/Wall_09.xpm");
	sprite->wall_04 = ft_new_sprite(prog->mlx, "./sprite/Wall_02.xpm");
	sprite->wall_05 = ft_new_sprite(prog->mlx, "./sprite/Wall_03.xpm");
	sprite->wall_06 = ft_new_sprite(prog->mlx, "./sprite/Wall_04.xpm");
	sprite->wall_07 = ft_new_sprite(prog->mlx, "./sprite/Wall_06.xpm");
	sprite->wall_08 = ft_new_sprite(prog->mlx, "./sprite/Wall_01.xpm");
	sprite->wall_09 = ft_new_sprite(prog->mlx, "./sprite/Wall_13.xpm");
	sprite->wall_10 = ft_new_sprite(prog->mlx, "./sprite/Wall_12.xpm");
	sprite->wall_11 = ft_new_sprite(prog->mlx, "./sprite/Wall_07.xpm");
	sprite->wall_12 = ft_new_sprite(prog->mlx, "./sprite/Wall_14.xpm");
	sprite->wall_13 = ft_new_sprite(prog->mlx, "./sprite/Wall_15.xpm");
	sprite->wall_14 = ft_new_sprite(prog->mlx, "./sprite/Wall_10.xpm");
	sprite->wall_15 = ft_new_sprite(prog->mlx, "./sprite/Wall_11.xpm");
	sprite->wall_16 = ft_new_sprite(prog->mlx, "./sprite/Wall_16.xpm");
	sprite->grass_00 = ft_new_sprite(prog->mlx, "./sprite/Grass_00.xpm");
	sprite->grass_01 = ft_new_sprite(prog->mlx, "./sprite/Grass_01.xpm");
	sprite->grass_02 = ft_new_sprite(prog->mlx, "./sprite/Grass_02.xpm");
	sprite->grass_03 = ft_new_sprite(prog->mlx, "./sprite/Grass_03.xpm");
	sprite->grass_04 = ft_new_sprite(prog->mlx, "./sprite/Grass_04.xpm");
	sprite->grass_05 = ft_new_sprite(prog->mlx, "./sprite/Grass_05.xpm");
	sprite->grass_07 = ft_new_sprite(prog->mlx, "./sprite/Grass_07.xpm");
	sprite->coin_01 = ft_new_sprite(prog->mlx, "./sprite/coin_01.xpm");
	sprite->floor_00 = ft_new_sprite(prog->mlx, "./sprite/Floor_00.xpm");
	sprite->p_floor = ft_new_sprite(prog->mlx, "./sprite/Grass_01.xpm");
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
