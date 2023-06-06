/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:40:55 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 15:48:20 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_pb(t_top *top_a, t_top *top_b)
{
	t_num	*temp;

	if (!top_a->first)
	{
		return (0);
	}
	temp = top_a->first;
	top_a->first = top_a->first->next;
	temp->next = top_b->first;
	top_b->first = temp;
	ft_printf("pb\n");
	return (0);
}

int	ft_sort_pa(t_top *top_a, t_top *top_b)
{
	t_num	*temp;

	if (!top_b->first)
	{
		return (0);
	}
	temp = top_b->first;
	top_b->first = top_b->first->next;
	temp->next = top_a->first;
	top_a->first = temp;
	ft_printf("pa\n");
	return (0);
}
