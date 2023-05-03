/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:20:50 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 13:48:03 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_check_sort(t_top *top)
{
	t_num	*idx;

	idx = top->first;
	while (idx->next)
	{
		if (idx->content > idx->next->content)
			return (0);
		idx = idx->next;
	}
	return (1);
}

int	ft_sort_radix(t_top *top_a, t_top *top_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_size_list(top_a);
	top_b->first = NULL;
	while (ft_check_sort(top_a) == 0)
	{
		while (j++ <= size)
		{
			if (((top_a->first->index >> i) & 1) == 0)
				ft_sort_pb(top_a, top_b);
			else
				ft_sort_ra(top_a);
		}
		j = 0;
		while (j++ <= size)
			ft_sort_pa(top_a, top_b);
		j = 0;
		i++;
	}
	return (0);
}
