/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:40:55 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 13:42:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_pb(t_top *top_a, t_top *top_b)
{
	int		num;
	int		index;
	t_num	*del;

	num = 0;
	if (!top_a->first)
		return (0);
	del = top_a->first;
	if (top_a != NULL && top_a->first != NULL)
	{
		num = del->content;
		index = del->index;
		top_a->first = del->next;
		free(del);
	}
	ft_num_add(top_b, num, index);
	ft_printf("pb\n");
	return (0);
}

int	ft_sort_pa(t_top *top_a, t_top *top_b)
{
	int		num;
	int		index;
	t_num	*del;

	num = 0;
	if (!top_b || !top_b->first)
	{
		return (0);
	}
	del = top_b->first;
	if (top_b != NULL && top_b->first != NULL)
	{
		num = del->content;
		index = del->index;
		top_b->first = del->next;
		free(del);
	}
	ft_num_add(top_a, num, index);
	ft_printf("pa\n");
	return (0);
}
