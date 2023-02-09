/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:44:19 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/09 08:44:51 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_print_list(t_top *top)
{
	t_num	*new;

	new = top->first;
	while (new)
	{
		printf("%d\n", new->content);
		new = new->next;
	}
	return (0);
}
