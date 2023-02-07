/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:16:09 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/07 06:11:36 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*new;
	int		i;
	int		*num;

	i = argc - 1;
	tmp = NULL;
	while (i > 0)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (0);
		num = (int *)malloc(sizeof(int));
		if (!num)
			return (0);
		*num = atoi(argv[i]);
		new->content = num;
		new->next = tmp;
		tmp = new;
		i--;
	}
	return (0);
}
