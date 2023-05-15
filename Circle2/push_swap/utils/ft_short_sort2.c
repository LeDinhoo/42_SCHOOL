/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:44:46 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/15 15:18:49 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_index_max(t_top *top)
{
	int		index;
	t_num	*tmp;

	index = 0;
	tmp = top->first;
	while (tmp)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

int	ft_find_min(t_top *top)
{
	int		index;
	t_num	*tmp;

	tmp = top->first;
	index = ft_index_max(top);
	while (tmp)
	{
		if (tmp->index < index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

int	ft_sort_four(t_top *top_a, t_top *top_b)
{
	t_num	*new;

	new = top_a->first;
	while (new->index != ft_find_min(top_a))
	{
		ft_sort_ra(top_a);
		new = top_a->first;
	}
	if (ft_check_sort(top_a) == 1)
		return (0);
	ft_sort_pb(top_a, top_b);
	ft_sort_three(top_a);
	ft_sort_pa(top_a, top_b);
	return (0);
}

void	ft_sort_five_bis(t_top *top_a)
{
	t_num	*new;

	new = top_a->first;
	if (new->next->next->next->index == 0)
	{
		ft_sort_rra(top_a);
		ft_sort_rra(top_a);
	}
	else if (new->next->next->next->next->index == 0)
	{
		ft_sort_rra(top_a);
	}
}

void	ft_sort_five(t_top *top_a, t_top *top_b)
{
	t_num	*new;

	new = top_a->first;
	if (new->next->index == 0)
	{
		ft_sort_ra(top_a);
	}
	else if (new->next->next->index == 0)
	{
		ft_sort_ra(top_a);
		ft_sort_ra(top_a);
	}
	ft_sort_five_bis(top_a);
	if (ft_check_sort(top_a) == 1)
		return ;
	ft_sort_pb(top_a, top_b);
	ft_sort_four(top_a, top_b);
	ft_sort_pa(top_a, top_b);
}
