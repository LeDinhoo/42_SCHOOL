/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:46:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/09 08:46:27 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_create_list(int size, char **argv, t_top *top, t_num *new)
{
	int		i;

	i = 1;
	if (!top || !new)
		return (0);
	new->content = ft_atoi(argv[i]);
	top->first = new;
	i++;
	while (i <= size)
	{
		new->next = malloc(sizeof(t_num));
		if (!new)
			return (0);
		new = new->next;
		new->content = ft_atoi(argv[i]);
		new->next = NULL;
		i++;
	}
	return (0);
}
