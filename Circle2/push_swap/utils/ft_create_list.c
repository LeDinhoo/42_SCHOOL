/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:46:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/18 12:44:44 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_num	*ft_index_min(t_top *top)
{
	t_num	*min;
	t_num	*num;
	int		value;

	num = top->first;
	while (num->index != -1)
		num = num->next;
	min = num;
	value = num->content;
	while (num)
	{
		if (num->index == -1 && num->content < value)
		{
			value = num->content;
			min = num;
		}
		num = num->next;
	}
	return (min);
}

int	ft_size_list(t_top *top)
{
	int		size;
	t_num	*new;

	size = 0;
	if (!top->first)
		return (0);
	new = top->first;
	while (new->next)
	{
		new = new->next;
		size++;
	}
	return (size);
}

int	ft_put_index(t_top *top)
{
	int		index;
	int		size;
	t_num	*new;

	index = 0;
	size = ft_size_list(top);
	while (index <= size)
	{
		new = ft_index_min(top);
		new->index = index;
		index++;
	}
	return (0);
}

int	ft_create_list(int size, char **argv, t_top *top, t_num *new)
{
	int		i;

	i = 1;
	if (!top || !new)
		return (0);
	new->content = ft_atoi(argv[i]);
	new->index = -1;
	top->first = new;
	i++;
	while (i <= size)
	{
		new->next = malloc(sizeof(t_num));
		if (!new->next)
		{
			free(new->next);
			return (0);
		}
		new = new->next;
		new->content = ft_atoi(argv[i]);
		new->index = -1;
		new->next = NULL;
		i++;
	}
	return (0);
}
