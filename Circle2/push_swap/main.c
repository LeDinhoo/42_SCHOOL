/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/07 12:27:54 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_sort_sa(t_stack *lst)
{
	t_stack	
}

int	main(int argc, char **argv)
{
	t_stack	*new;
	int		i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (0);
		new->content = ft_atoi(argv[i]);
		new->next = NULL;
		new = new->next;
		i++;
	}
	return (0);
}
