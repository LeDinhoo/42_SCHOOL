/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:03:15 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/14 11:55:29 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_all_sprite(t_sprite *sprite, t_program *p, t_player *pl)
{
	sprite->spawn = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-16.xpm", p);
	sprite->spawn_01 = ft_new_sprite(p->mlx, "./sprite/Spawn_01.xpm", p);
	sprite->obj_00 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-4.xpm", p);
	sprite->obj_01 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-5.xpm", p);
	sprite->obj_02 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-6.xpm", p);
	sprite->obj_03 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-7.xpm", p);
	sprite->obj_04 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-8.xpm", p);
	sprite->obj_05 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-9.xpm", p);
	sprite->obj_06 = ft_new_sprite(p->mlx, "./sprite/calice/Calice-10.xpm", p);
	pl->py = ft_new_sprite(p->mlx, "./sprite/Rune.xpm", p);
	ft_sprite_grass(sprite, p);
	ft_sprite_wall(sprite, p);
	ft_sprite_smoke(sprite, p);
	return (0);
}

int	ft_sprite_grass(t_sprite *sprite, t_program *p)
{
	sprite->floor_00 = ft_new_sprite(p->mlx, "./sprite/Floor_00.xpm", p);
	sprite->p_floor = ft_new_sprite(p->mlx, "./sprite/grass/Grass_01.xpm", p);
	sprite->grass_00 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_00.xpm", p);
	sprite->grass_01 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_01.xpm", p);
	sprite->grass_02 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_02.xpm", p);
	sprite->grass_03 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_03.xpm", p);
	sprite->grass_04 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_04.xpm", p);
	sprite->grass_05 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_05.xpm", p);
	sprite->grass_07 = ft_new_sprite(p->mlx, "./sprite/grass/Grass_07.xpm", p);
	return (0);
}

int	ft_sprite_wall(t_sprite *sprite, t_program *p)
{
	sprite->wall_01 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_05.xpm", p);
	sprite->wall_02 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_0.xpm", p);
	sprite->wall_03 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_09.xpm", p);
	sprite->wall_04 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_02.xpm", p);
	sprite->wall_05 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_03.xpm", p);
	sprite->wall_06 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_04.xpm", p);
	sprite->wall_07 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_06.xpm", p);
	sprite->wall_08 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_01.xpm", p);
	sprite->wall_09 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_13.xpm", p);
	sprite->wall_10 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_12.xpm", p);
	sprite->wall_11 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_07.xpm", p);
	sprite->wall_12 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_14.xpm", p);
	sprite->wall_13 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_15.xpm", p);
	sprite->wall_14 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_10.xpm", p);
	sprite->wall_15 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_11.xpm", p);
	sprite->wall_16 = ft_new_sprite(p->mlx, "./sprite/wall/Wall_16.xpm", p);
	return (0);
}

int	ft_sprite_smoke(t_sprite *sprite, t_program *p)
{
	sprite->smoke_00 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-0.xpm", p);
	sprite->smoke_01 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-1.xpm", p);
	sprite->smoke_02 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-2.xpm", p);
	sprite->smoke_03 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-3.xpm", p);
	sprite->smoke_04 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-4.xpm", p);
	sprite->smoke_05 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-5.xpm", p);
	sprite->smoke_06 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-6.xpm", p);
	sprite->smoke_07 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-7.xpm", p);
	sprite->smoke_08 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-8.xpm", p);
	sprite->smoke_09 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-9.xpm", p);
	sprite->smoke_10 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-10.xpm", p);
	sprite->smoke_11 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-11.xpm", p);
	sprite->smoke_12 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-12.xpm", p);
	sprite->smoke_13 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-13.xpm", p);
	sprite->smoke_14 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-14.xpm", p);
	sprite->smoke_15 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-15.xpm", p);
	sprite->smoke_16 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-16.xpm", p);
	sprite->smoke_17 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-17.xpm", p);
	sprite->smoke_18 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-18.xpm", p);
	sprite->smoke_19 = ft_new_sprite(p->mlx, "./sprite/smoke/Smoke-19.xpm", p);
	return (0);
}

t_image	ft_new_sprite(void *mlx, char *path, t_program *prog)
{
	t_image_node	*node;

	node = malloc(sizeof(t_image_node));
	if (node == NULL)
		free(node);
	node->image.ref = mlx_xpm_file_to_image(mlx, path,
			&node->image.size.x, &node->image.size.y);
	if (node->image.ref == NULL)
	{
		ft_printf("Error: Unable to create the XPM file. %s\n", path);
		free(node);
		ft_end(prog);
	}
	node->image.addr = mlx_get_data_addr(node->image.ref,
			&node->image.bits_per_pixel,
			&node->image.line_size, &node->image.endian);
	node->next = prog->g_image_list;
	prog->g_image_list = node;
	return (node->image);
}
