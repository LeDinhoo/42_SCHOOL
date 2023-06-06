/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:44:19 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 16:47:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_print_list(t_top *top)
{
	t_num	*new;

	new = top->first;
	while (new)
	{
		ft_printf("%d index : %d\n", new->content, new->index);
		new = new->next;
	}
	return (0);
}

void	error_msg(char *msg, char **argv, int is_modified)
{
	ft_putendl_fd(msg, 2);
	if (is_modified && argv != NULL)
		ft_free(argv);
	exit(0);
}
