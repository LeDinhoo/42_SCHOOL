/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/25 15:27:12 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_right(void *param)
{
	t_program	*p;
	int			i;

	p = (t_program *)param;
	i = 0;
	while (i < 28)
	{
		if (p->map[(p->player.pos.y + i) / 64][(p->player.pos.x + 30) / 64]
			== '1' && p->player.x_dir == 1)
			return (0);
		if (p->map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 15) / 64] == 'C')
		{
			p->map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 15) / 64] = '0';
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
	while (i < 28)
	{
		if (p->map[(p->player.pos.y + i) / 64][(p->player.pos.x - 3) / 64]
			== '1' && p->player.x_dir == -1)
			return (0);
		if (p->map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 15) / 64] == 'C')
		{
			p->map[(p->player.pos.y + i) / 64]
			[(p->player.pos.x + 15) / 64] = '0';
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
		if (p->map[(p->player.pos.y - 3) / 64][(p->player.pos.x + i) / 64]
			== '1' && p->player.y_dir == -1)
			return (0);
		if (p->map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] == 'C')
		{
			p->map[(p->player.pos.y + 15) / 64]
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
		if (p->map[(p->player.pos.y + 30) / 64][(p->player.pos.x + i) / 64]
			== '1' && p->player.y_dir == 1)
			return (0);
		if (p->map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] == 'C')
		{
			p->map[(p->player.pos.y + 15) / 64]
			[(p->player.pos.x + i) / 64] = '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	key_press(int key, void *param)
{
	t_program	*p;

	p = (t_program *)param;
	if (key == 2)
			p->player.x_dir = 1;
	if (key == 13)
			p->player.y_dir = -1;
	if (key == 1)
			p->player.y_dir = 1;
	if (key == 0)
			p->player.x_dir = -1;
	printf("%d\n", key);
	return (0);
}
