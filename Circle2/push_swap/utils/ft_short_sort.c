/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:24:42 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 17:43:45 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_two(t_top *top_a)
{
	ft_sort_ra(top_a);
	return (0);
}

int	ft_simple_three(t_top *top_a)
{
	ft_sort_ra(top_a);
	ft_sort_sa(top_a);
	ft_sort_rra(top_a);
	return (0);
}

int	ft_sort_three(t_top *top_a)
{
	t_num	*new;

	new = top_a->first;
	if (new->index == ft_index_max(top_a))
	{
		if (new->next->index == ft_find_min(top_a))
			ft_sort_ra(top_a);
		else
		{
			ft_sort_sa(top_a);
			ft_sort_rra(top_a);
		}
	}
	else if (new->index != ft_index_max(top_a)
		&& new->index != ft_find_min(top_a))
	{
		if (new->next->index == ft_index_max(top_a))
			ft_sort_rra(top_a);
		else
			ft_sort_sa(top_a);
	}
	else
		ft_simple_three(top_a);
	return (0);
}

int	ft_short_sort(t_top *top_a, t_top *top_b)
{
	if (ft_size_list(top_a) == 1)
		ft_sort_two(top_a);
	if (ft_size_list(top_a) == 2)
		ft_sort_three(top_a);
	if (ft_size_list(top_a) == 3)
		ft_sort_four(top_a, top_b);
	if (ft_size_list(top_a) == 4)
		ft_sort_five(top_a, top_b);
	return (0);
}
