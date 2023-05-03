/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 13:47:42 by hdupuy           ###   ########.fr       */
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

int	ft_isnum(char *num)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (num[i])
	{
		if (sign > 1)
			return (0);
		if (num[i] == '+' || num[i] == '-')
		{
			i++;
			sign++;
		}
		if (num[i] > 57 || num[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_check_arg(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (ft_isnum(argv[i]) == 0)
			return (0);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	if (ft_check_double(argv) == 0)
		return (0);
	return (1);
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
	{
		write (2, "Error\n", 7);
		exit (0);
	}
	top_a = malloc(sizeof(t_top));
	if (!top_a)
		return (0);
	top_b = malloc(sizeof(t_top));
	if (!top_b)
		return (0);
	a = malloc(sizeof(t_num));
	ft_create_list(size, argv, top_a, a);
	ft_put_index(top_a);
	if (ft_check_sort(top_a) == 0)
	{
		if (argc <= 5)
			ft_short_sort(top_a, top_b, argc);
		if (argc > 5)
			ft_sort_radix(top_a, top_b);
	}
	ft_free_list(top_a);
	if (argc < 6)
		top_b->first = NULL;
	ft_free_list(top_b);
	return (0);
}
