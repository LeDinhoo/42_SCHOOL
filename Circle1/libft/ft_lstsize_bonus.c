/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:25:22 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/15 11:34:40 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	idx;
	t_list	*tmp;

	idx = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		idx++;
	}
	return (idx);
}
