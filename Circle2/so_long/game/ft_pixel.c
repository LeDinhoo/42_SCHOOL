/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:12 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/26 23:25:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// void	ft_read_player_by_pix(t_program *p, t_image player)
// {
// 	unsigned int	color;
// 	int				i;
// 	int				y;

// 	i = 0;
// 	while (i < 28)
// 	{
// 		y = 0;
// 		while (y < 28)
// 		{
// 			color = ft_take_color(&player, i, y);
// 			if (color != 0xFF000000)
// 				my_mlx_pixel_put(&p->img, p->player.pos.x + i,
// 					p->player.pos.y + y, color);
// 			y++;
// 		}
// 		i++;
// 	}
// }

// unsigned int	ft_take_color(t_image *data, int i, int y)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size.x + i
// 			* (data->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

// void	my_mlx_pixel_put(t_image *data, int i, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size.x + i * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
