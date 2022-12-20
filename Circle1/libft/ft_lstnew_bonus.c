/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:03:04 by hdupuy            #+#    #+#             */
/*   Updated: 2022/12/15 15:35:08 by hdupuy           ###   ########.fr       */
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

#include <stdio.h>

int main(void)
{
    int *value = malloc(sizeof(int));
    *value = 42;

    t_list *newlist = ft_lstnew(value);
    if (newlist)
    {
        printf("New list created with value %d\n", *(int*)newlist->content);
    }
    else
    {
        printf("Failed to create new list\n");
    }

    return 0;
}
