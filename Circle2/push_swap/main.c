/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 17:05:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_free_list(t_top *top)
{
	t_num	*node;
	t_num	*temp;

	if (!top->first)
	{
		free(top);
		return ;
	}
	node = top->first;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	top->first = NULL;
	free(top);
}

int	ft_error(void)
{
	write (2, "Error\n", 7);
	exit (0);
}

int	ft_choose_sort(t_top *top_a, t_top *top_b)
{
	if (ft_check_sort(top_a) == 0)
	{
		if (ft_size_list(top_a) <= 4)
			ft_short_sort(top_a, top_b);
		if (ft_size_list(top_a) > 4)
			ft_sort_radix(top_a, top_b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_top	*top_a;
	t_top	*top_b;
	t_num	*a;

	if (argc < 2)
		return (0);
	ft_check_arg(argv, argc);
	top_a = malloc(sizeof(t_top));
	top_b = malloc(sizeof(t_top));
	if (!top_a || !top_b)
		return (0);
	a = malloc(sizeof(t_num));
	ft_create_list(argc, argv, top_a, a);
	ft_put_index(top_a);
	ft_choose_sort(top_a, top_b);
	ft_free_list(top_a);
	if (argc <= 6)
		top_b->first = NULL;
	ft_free_list(top_b);
	return (0);
}
