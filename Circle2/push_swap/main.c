/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 14:01:41 by hdupuy           ###   ########.fr       */
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

int	ft_choose_sort(t_top *top_a, t_top *top_b, int argc)
{
	if (ft_check_sort(top_a) == 0)
	{
		if (argc <= 5)
			ft_short_sort(top_a, top_b, argc);
		if (argc > 5)
			ft_sort_radix(top_a, top_b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		size;
	t_top	*top_a;
	t_top	*top_b;
	t_num	*a;

	size = argc - 1;
	if (argc == 1)
		return (0);
	if (ft_check_arg(argv) == 0)
		ft_error();
	top_a = malloc(sizeof(t_top));
	top_b = malloc(sizeof(t_top));
	if (!top_a || !top_b)
		return (0);
	a = malloc(sizeof(t_num));
	ft_create_list(size, argv, top_a, a);
	ft_put_index(top_a);
	ft_free_list(top_a);
	if (argc < 6)
		top_b->first = NULL;
	ft_free_list(top_b);
	return (0);
}
