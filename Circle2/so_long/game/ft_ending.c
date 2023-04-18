/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:46:53 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/18 09:49:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_obj_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	*ft_free(t_program *p)
{
	int		i;

	i = 0;
	if (p->map.map != NULL)
	{
		while (p->map.map[i] != NULL)
		{
			free(p->map.map[i]);
			i++;
		}
		free(p->map.map);
	}
	return (0);
}

void	ft_free_images(t_program *p)
{
	t_image_node	*node;
	t_image_node	*temp;

	node = p->g_image_list;
	while (node != NULL)
	{
		mlx_destroy_image(p->mlx, node->image.ref);
		temp = node;
		node = node->next;
		free(temp);
	}
	p->g_image_list = NULL;
}

int	ft_end(t_program *p)
{
	ft_free(p);
	ft_free_images(p);
	mlx_destroy_window(p->mlx, p->window.ref);
	mlx_destroy_display(p->mlx);
	if (p->mlx)
		free(p->mlx);
	exit(0);
}

int	ft_finish(t_program *p)
{
	if (p->map.map[(p->player.pos.y + 26) / 64]
		[(p->player.pos.x - 10) / 64] == 'E')
	{
		if (ft_obj_check(p->map.map))
		{
			write(1, "Good game !", 11);
			ft_end(p);
		}
	}
	return (0);
}
