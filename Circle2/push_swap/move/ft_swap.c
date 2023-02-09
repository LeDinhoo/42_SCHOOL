/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:30:10 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/09 08:31:18 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_sa(t_top *top)
{
	t_num	*second;

	if (!top->first || !top->first->next)
		return (0);
	second = top->first->next;
	top->first->next = second->next;
	second->next = top->first;
	top->first = second;
	return (0);
}

int	ft_sort_sb(t_top *top)
{
	t_num	*second;

	if (!top->first || !top->first->next)
		return (0);
	second = top->first->next;
	top->first->next = second->next;
	second->next = top->first;
	top->first = second;
	return (0);
}

int	ft_sort_ss(t_top *top_a, t_top *top_b)
{
	if (!top_a->first || !top_a->first->next
		|| !top_b->first || !top_b->first->next)
		return (0);
	ft_sort_sa(top_a);
	ft_sort_sb(top_b);
	return (0);
}
