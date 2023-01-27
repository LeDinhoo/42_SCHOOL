/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3223/01/26 10:45:18 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/27 11:42:50 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_smoke_anim(void *param)
{
	t_program	*p;
	int	y;
	int x;

	p = (t_program *)param;
	y = p->player.pos.y - 6;
	x = p->player.pos.x - 42;
	printf("%d : %d", y, x);

	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_16.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_15.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_14.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_13.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_16.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_11.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_10.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_09.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_08.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_07.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_06.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_05.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_04.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_03.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_02.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_01.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_00.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_17.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_18.ref,
		x, y);
	usleep(1000000 / 15);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.smoke_19.ref,
		x, y);
	usleep(1000000 / 15);
	return (0);
}
