/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/09 08:46:00 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	t_top	*top_a;
	t_top	*top_b;
	t_num	*a;

	size = argc - 1;
	if (argc == 1)
		return (0);
	top_a = malloc(sizeof(t_top));
	top_b = malloc(sizeof(t_top));
	a = malloc(sizeof(t_num));
	ft_create_list(size, argv, top_a, a);
	ft_sort_rra(top_a);
	printf("Liste A:\n");
	ft_print_list(top_a);
	printf("Liste B:\n");
	ft_print_list(top_b);
	return (0);
}
