/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:03:15 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/12 15:43:52 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p)
{
	sprite->spawn = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-16.xpm", prog);
	sprite->spawn_01 = ft_new_sprite(prog->mlx, "./sprite/Spawn_01.xpm", prog);
	sprite->obj_00 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-4.xpm", prog);
	sprite->obj_01 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-5.xpm", prog);
	sprite->obj_02 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-6.xpm", prog);
	sprite->obj_03 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-7.xpm", prog);
	sprite->obj_04 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-8.xpm", prog);
	sprite->obj_05 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-9.xpm", prog);
	sprite->obj_06 = ft_new_sprite(prog->mlx, "./sprite/calice/Calice-10.xpm", prog);
	p->py = ft_new_sprite(prog->mlx, "./sprite/Rune.xpm", prog);
	ft_sprite_grass(sprite, prog);
	ft_sprite_wall(sprite, prog);
	ft_sprite_smoke(sprite, prog);
	return (0);
}

int	ft_sprite_grass(t_sprite *sprite, t_program *prog)
{
	sprite->floor_00 = ft_new_sprite(prog->mlx, "./sprite/Floor_00.xpm", prog);
	sprite->p_floor = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_01.xpm", prog);
	sprite->grass_00 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_00.xpm", prog);
	sprite->grass_01 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_01.xpm", prog);
	sprite->grass_02 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_02.xpm", prog);
	sprite->grass_03 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_03.xpm", prog);
	sprite->grass_04 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_04.xpm", prog);
	sprite->grass_05 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_05.xpm", prog);
	sprite->grass_07 = ft_new_sprite(prog->mlx, "./sprite/grass/Grass_07.xpm", prog);
	return (0);
}

int	ft_sprite_wall(t_sprite *sprite, t_program *prog)
{
	sprite->wall_01 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_05.xpm", prog);
	sprite->wall_02 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_0.xpm", prog);
	sprite->wall_03 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_09.xpm", prog);
	sprite->wall_04 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_02.xpm", prog);
	sprite->wall_05 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_03.xpm", prog);
	sprite->wall_06 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_04.xpm", prog);
	sprite->wall_07 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_06.xpm", prog);
	sprite->wall_08 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_01.xpm", prog);
	sprite->wall_09 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_13.xpm", prog);
	sprite->wall_10 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_12.xpm", prog);
	sprite->wall_11 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_07.xpm", prog);
	sprite->wall_12 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_14.xpm", prog);
	sprite->wall_13 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_15.xpm", prog);
	sprite->wall_14 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_10.xpm", prog);
	sprite->wall_15 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_11.xpm", prog);
	sprite->wall_16 = ft_new_sprite(prog->mlx, "./sprite/wall/Wall_16.xpm", prog);
	return (0);
}

int	ft_sprite_smoke(t_sprite *sprite, t_program *prog)
{
	sprite->smoke_00 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-0.xpm", prog);
	sprite->smoke_01 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-1.xpm", prog);
	sprite->smoke_02 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-2.xpm", prog);
	sprite->smoke_03 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-3.xpm", prog);
	sprite->smoke_04 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-4.xpm", prog);
	sprite->smoke_05 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-5.xpm", prog);
	sprite->smoke_06 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-6.xpm", prog);
	sprite->smoke_07 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-7.xpm", prog);
	sprite->smoke_08 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-8.xpm", prog);
	sprite->smoke_09 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-9.xpm", prog);
	sprite->smoke_10 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-10.xpm", prog);
	sprite->smoke_11 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-11.xpm", prog);
	sprite->smoke_12 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-12.xpm", prog);
	sprite->smoke_13 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-13.xpm", prog);
	sprite->smoke_14 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-14.xpm", prog);
	sprite->smoke_15 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-15.xpm", prog);
	sprite->smoke_16 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-16.xpm", prog);
	sprite->smoke_17 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-17.xpm", prog);
	sprite->smoke_18 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-18.xpm", prog);
	sprite->smoke_19 = ft_new_sprite(prog->mlx, "./sprite/smoke/Smoke-19.xpm", prog);
	return (0);
}

t_image	ft_new_sprite(void *mlx, char *path, t_program *prog)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (img.ref == NULL)
	{
		ft_printf("Fail to load %s", path);
		ft_end(prog);
	}
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}
