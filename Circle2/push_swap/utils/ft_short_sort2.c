/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:44:46 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 15:45:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_fourthree(t_top *top_a)
{
	t_num	*new;

	new = top_a->first;
	if (new->index == 3)
		ft_sort_ra(top_a);
	if ((ft_check_sort(top_a) == 1))
		return (0);
	while (new->next)
		new = new->next;
	if (new->index == 3)
		ft_sort_sa(top_a);
	return (0);
}

int	ft_sort_four(t_top *top_a, t_top *top_b)
{
	t_num	*new;

	new = top_a->first;
	while (new->index != 0)
	{
		ft_sort_ra(top_a);
		new = top_a->first;
	}
	ft_sort_pb(top_a, top_b);
	ft_sort_fourthree(top_a);
	ft_sort_pa(top_a, top_b);
	return (0);
}

void	ft_sort_five(t_top *top_a, t_top *top_b)
{
	t_num	*new;

	new = top_a->first;
	if (new->index == 0)
		ft_sort_ra(top_a);
	else if (new->next->index == 0)
	{
		ft_sort_ra(top_a);
		ft_sort_ra(top_a);
	}
	else if (new->next->next->index == 0)
	{
		ft_sort_rra(top_a);
		ft_sort_rra(top_a);
	}
	else if (new->next->next->next->index == 0)
		ft_sort_rra(top_a);
	if (ft_check_sort(top_a) == 1)
		return ;
	ft_sort_pb(top_a, top_b);
	ft_sort_four(top_a, top_b);
	ft_sort_pa(top_a, top_b);
}
