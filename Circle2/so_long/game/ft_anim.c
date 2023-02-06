/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3223/01/26 10:45:18 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/30 10:35:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_smoke_anim1(t_program *p, int y, int x, int frame)
{
	if (frame == 1)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_16.ref, x, y);
	}
	if (frame == FRAMES * 1)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_15.ref, x, y);
	}
	if (frame == FRAMES * 2)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_14.ref, x, y);
	}
	if (frame == FRAMES * 3)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_13.ref, x, y);
	}
	return (0);
}

int	ft_smoke_anim2(t_program *p, int y, int x, int frame)
{
	if (frame == FRAMES * 4)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_12.ref, x, y);
	}
	if (frame == FRAMES * 5)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_11.ref, x, y);
	}
	if (frame == FRAMES * 6)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_10.ref, x, y);
	}
	if (frame == FRAMES * 7)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_09.ref, x, y);
	}
	return (0);
}

int	ft_smoke_anim3(t_program *p, int y, int x, int frame)
{
	if (frame == FRAMES * 8)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_08.ref, x, y);
	}
	if (frame == FRAMES * 9)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_07.ref, x, y);
	}
	if (frame == FRAMES * 10)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_06.ref, x, y);
	}
	if (frame == FRAMES * 11)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_05.ref, x, y);
	}
	return (0);
}

int	ft_smoke_anim4(t_program *p, int y, int x, int frame)
{
	if (frame == FRAMES * 12)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_04.ref, x, y);
	}
	if (frame == FRAMES * 13)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_03.ref, x, y);
	}
	if (frame == FRAMES * 14)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_02.ref, x, y);
	}
	if (frame == FRAMES * 15)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_01.ref, x, y);
	}
	return (0);
}

int	ft_smoke_anim5(t_program *p, int y, int x, int frame)
{
	if (frame == FRAMES * 16)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_00.ref, x, y);
	}
	if (frame == FRAMES * 17)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_17.ref, x, y);
	}
	if (frame == FRAMES * 18)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_18.ref, x, y);
	}
	if (frame == FRAMES * 19)
	{
		mlx_put_image_to_window(p->mlx, p->window.ref,
			p->sprite.smoke_19.ref, x, y);
	}
	return (0);
}
