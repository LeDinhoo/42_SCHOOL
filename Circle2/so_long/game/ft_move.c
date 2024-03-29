/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/12 13:35:53 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_right(void *param)
{
	t_program	*p;
	int			i;

	p = (t_program *)param;
	i = 0;
	while (i < 38)
	{
		if (p->map.map[(p->player.pos.y + i) / 64][(p->player.pos.x + 28) / 64]
			== '1' && p->player.x_dir == 1)
			return (0);
		if (p->map.map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 13) / 64] == 'C')
		{
			p->map.map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 13) / 64] = '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_check_left(void *param)
{
	t_program	*p;
	int			i;

	p = (t_program *)param;
	i = 0;
	while (i < 38)
	{
		if (p->map.map[(p->player.pos.y + i) / 64][(p->player.pos.x - 3) / 64]
			== '1' && p->player.x_dir == -1)
			return (0);
		if (p->map.map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x) / 64] == 'C')
		{
			p->map.map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x) / 64] = '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_check_up(void *param)
{
	t_program	*p;
	int			i;

	p = (t_program *)param;
	i = 0;
	while (i < 28)
	{
		if (p->map.map[(p->player.pos.y - 3) / 64][(p->player.pos.x + i) / 64]
			== '1' && p->player.y_dir == -1)
			return (0);
		if (p->map.map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] == 'C')
		{
			p->map.map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] = '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_check_down(void *param)
{
	t_program	*p;
	int			i;

	p = (t_program *)param;
	i = 0;
	while (i < 28)
	{
		if (p->map.map[(p->player.pos.y + 40) / 64][(p->player.pos.x + i) / 64]
			== '1' && p->player.y_dir == 1)
			return (0);
		if (p->map.map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] == 'C')
		{
			p->map.map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] = '0';
			return (1);
		}
		i++;
	}
	return (1);
}
