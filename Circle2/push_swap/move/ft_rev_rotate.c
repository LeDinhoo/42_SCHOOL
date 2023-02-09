/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:39:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/09 08:40:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_rrb(t_top *top)
{
	int		num;
	t_num	*del;
	t_num	*prev;

	num = 0;
	if (!top->first)
		return (0);
	if (!top && !top->first && !top->first->next)
	{
		del = top->first;
		while (del->next)
		{
			prev = del;
			del = del->next;
		}
		num = del->content;
		prev->next = NULL;
		free(del);
	}
	ft_num_add(top, num);
	return (0);
}

int	ft_sort_rra(t_top *top)
{
	int		num;
	t_num	*del;
	t_num	*prev;

	num = 0;
	if (!top->first)
		return (0);
	if (!top && !top->first && !top->first->next)
	{
		del = top->first;
		while (del->next)
		{
			prev = del;
			del = del->next;
		}
		num = del->content;
		prev->next = NULL;
		free(del);
	}
	ft_num_add(top, num);
	return (0);
}

int	ft_sort_rrr(t_top *top_a, t_top *top_b)
{
	if (!top_a->first || !top_b->first)
		return (0);
	ft_sort_rra(top_a);
	ft_sort_rrb(top_b);
	return (0);
}
