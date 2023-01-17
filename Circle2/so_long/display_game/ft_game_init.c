/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/17 17:12:40 by hdupuy           ###   ########.fr       */
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

int	ft_display_init(t_map *map)
{
	t_program	program;
	int	y;
	int	x;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, (map->width * 40),
			(map->height * 40), "Bonjour !");
	program.sprite = ft_new_sprite(program.mlx, "./display_game/block.xpm");
	program.sprite_position.y = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		program.sprite_position.x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
			{
				mlx_put_image_to_window(program.mlx, program.window.ref,
					program.sprite.ref, program.sprite_position.x,
					program.sprite_position.y);
				program.sprite_position.x = (x * 40);
				program.sprite_position.y = (y * 40);
			}
			printf("%d\n", x);
			x++;
		}
		y++;
	}
	mlx_loop(program.mlx);
	return (0);
}
