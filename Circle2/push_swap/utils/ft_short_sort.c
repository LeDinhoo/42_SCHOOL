/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:24:42 by hdupuy            #+#    #+#             */
/*   Updated: 2023/03/07 14:36:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_sort_two(t_top *top_a)
{
	if ((ft_check_sort(top_a) == 1))
		return (0);
	ft_sort_ra(top_a);
	return (0);
}

int	ft_sort_three(t_top *top_a)
{
	t_num	*new;

	new = top_a->first;
	if (new->index == 2)
		ft_sort_ra(top_a);
	if ((ft_check_sort(top_a) == 1))
		return (0);
	while (new->next)
		new = new->next;
	if (new->index == 2)
		ft_sort_sa(top_a);
	return (0);
}

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

int	ft_short_sort(t_top *top_a, t_top *top_b, int argc)
{
	if (argc == 3)
		ft_sort_two(top_a);
	if (argc == 4)
		ft_sort_three(top_a);
	if (argc == 5)
		ft_sort_four(top_a, top_b);
	exit (0);
}
