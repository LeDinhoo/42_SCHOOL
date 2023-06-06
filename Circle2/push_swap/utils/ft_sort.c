/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:20:50 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 17:03:58 by hdupuy           ###   ########.fr       */
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

int	ft_get_max_bits(t_top *top_a)
{
	t_num	*tmp;
	int		max;
	int		max_bits;

	tmp = top_a->first;
	if (!tmp)
		return (0);
	max_bits = 0;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	move_elements(t_top *top_a, t_top *top_b, int i, int size)
{
	int	j;

	j = 0;
	while (j++ < size)
	{
		if (top_a->first == NULL)
			break ;
		if (((top_a->first->index >> i) & 1) == 1)
			ft_sort_ra(top_a);
		else
			ft_sort_pb(top_a, top_b);
	}
}

void	restore_elements(t_top *top_a, t_top *top_b)
{
	while (top_b->first)
		ft_sort_pa(top_a, top_b);
}

int	ft_sort_radix(t_top *top_a, t_top *top_b)
{
	int	i;
	int	size;
	int	maxbits;

	i = 0;
	size = ft_size_list(top_a) + 1;
	maxbits = ft_get_max_bits(top_a);
	top_b->first = NULL;
	while (i < maxbits)
	{
		move_elements(top_a, top_b, i, size);
		restore_elements(top_a, top_b);
		i++;
	}
	return (0);
}
