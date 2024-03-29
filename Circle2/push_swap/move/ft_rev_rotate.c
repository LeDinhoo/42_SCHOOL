/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:39:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/29 12:04:26 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_rrb(t_top *top)
{
	int		num;
	int		index;
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
		index = del->index;
		prev->next = NULL;
		free(del);
	}
	ft_num_add(top, num, index);
	ft_printf("rrb\n");
	return (0);
}

int	ft_sort_rra(t_top *top)
{
	t_num	*last;
	t_num	*prev;

	if (!top->first || !top->first->next)
		return (0);
	last = top->first;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
	{
		prev->next = NULL;
	}
	last->next = top->first;
	top->first = last;
	ft_printf("rra\n");
	return (0);
}

int	ft_sort_rrr(t_top *top_a, t_top *top_b)
{
	if (!top_a->first || !top_b->first)
		return (0);
	ft_sort_rra(top_a);
	ft_sort_rrb(top_b);
	ft_printf("rrr\n");
	return (0);
}
