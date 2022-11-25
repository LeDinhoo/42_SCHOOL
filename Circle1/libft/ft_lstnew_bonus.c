/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:03:04 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/15 11:07:09 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelement;

	newelement = malloc(sizeof(t_list));
	if (!newelement)
		return (NULL);
	newelement->content = content;
	newelement->next = NULL;
	return (newelement);
}
