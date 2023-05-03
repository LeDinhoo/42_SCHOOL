/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:36:39 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 13:44:37 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_rb(t_top *top)
{
	int		num;
	int		index;
	t_num	*del;

	num = 0;
	if (!top->first)
		return (0);
	del = top->first;
	if (top != NULL && top->first != NULL)
	{
		num = del->content;
		index = del->index;
		top->first = del->next;
		free(del);
	}
	ft_num_addback(top, num, index);
	ft_printf("rb\n");
	return (0);
}

int	ft_sort_ra(t_top *top)
{
	int		num;
	int		index;
	t_num	*del;

	num = 0;
	if (!top->first)
		return (0);
	del = top->first;
	if (top != NULL && top->first != NULL)
	{
		num = del->content;
		index = del->index;
		top->first = del->next;
		free(del);
	}
	ft_num_addback(top, num, index);
	ft_printf("ra\n");
	return (0);
}

int	ft_sort_rr(t_top *top_a, t_top *top_b)
{
	if (!top_a->first || !top_b->first)
		return (0);
	ft_sort_ra(top_a);
	ft_sort_rb(top_b);
	ft_printf("rr\n");
	return (0);
}
