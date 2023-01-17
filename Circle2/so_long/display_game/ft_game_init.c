/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:56 by hdupuy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/17 17:12:40 by hdupuy           ###   ########.fr       */
=======
/*   Updated: 2023/01/12 18:05:27 by hdupuy           ###   ########.fr       */
>>>>>>> e14bc5a405f175a2f89797a077729776528b69cc
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

<<<<<<< HEAD
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
=======
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_display_init(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	img2;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Bonjour");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 80, 80);
	mlx_loop(mlx);
>>>>>>> e14bc5a405f175a2f89797a077729776528b69cc
}
