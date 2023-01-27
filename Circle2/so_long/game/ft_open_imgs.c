/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:03:15 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/27 14:05:19 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->spawn = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-16.xpm");
	sprite->spawn_01 = ft_new_sprite(prog->mlx, "./sprite/Spawn_01.xpm");
	sprite->obj_00 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-4.xpm");
	sprite->obj_01 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-5.xpm");
	sprite->obj_02 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-6.xpm");
	sprite->obj_03 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-7.xpm");
	sprite->obj_04 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-8.xpm");
	sprite->obj_05 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-9.xpm");
	sprite->obj_06 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-10.xpm");
	p->py = ft_new_sprite(prog->mlx, "./sprite/Rune.xpm");
	ft_sprite_grass(sprite, prog, p);
	ft_sprite_wall(sprite, prog, p);
	ft_sprite_smoke(sprite, prog, p);
	return (0);
}

int	ft_sprite_grass(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->floor_00 = ft_new_sprite(prog->mlx, "./sprite/Floor_00.xpm");
	sprite->p_floor = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_01.xpm");
	sprite->grass_00 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_00.xpm");
	sprite->grass_01 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_01.xpm");
	sprite->grass_02 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_02.xpm");
	sprite->grass_03 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_03.xpm");
	sprite->grass_04 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_04.xpm");
	sprite->grass_05 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_05.xpm");
	sprite->grass_07 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_07.xpm");
}

int	ft_sprite_wall(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->wall_01 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_05.xpm");
	sprite->wall_02 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_0.xpm");
	sprite->wall_03 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_09.xpm");
	sprite->wall_04 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_02.xpm");
	sprite->wall_05 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_03.xpm");
	sprite->wall_06 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_04.xpm");
	sprite->wall_07 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_06.xpm");
	sprite->wall_08 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_01.xpm");
	sprite->wall_09 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_13.xpm");
	sprite->wall_10 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_12.xpm");
	sprite->wall_11 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_07.xpm");
	sprite->wall_12 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_14.xpm");
	sprite->wall_13 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_15.xpm");
	sprite->wall_14 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_10.xpm");
	sprite->wall_15 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_11.xpm");
	sprite->wall_16 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_16.xpm");
}

int	ft_sprite_smoke(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->smoke_00 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-0.xpm");
	sprite->smoke_01 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-1.xpm");
	sprite->smoke_02 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-2.xpm");
	sprite->smoke_03 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-3.xpm");
	sprite->smoke_04 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-4.xpm");
	sprite->smoke_05 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-5.xpm");
	sprite->smoke_06 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-6.xpm");
	sprite->smoke_07 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-7.xpm");
	sprite->smoke_08 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-8.xpm");
	sprite->smoke_09 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-9.xpm");
	sprite->smoke_10 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-10.xpm");
	sprite->smoke_11 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-11.xpm");
	sprite->smoke_12 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-12.xpm");
	sprite->smoke_13 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-13.xpm");
	sprite->smoke_14 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-14.xpm");
	sprite->smoke_15 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-15.xpm");
	sprite->smoke_16 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-16.xpm");
	sprite->smoke_17 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-17.xpm");
	sprite->smoke_18 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-18.xpm");
	sprite->smoke_19 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-19.xpm");
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}
