/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:33:48 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 16:13:42 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_num_add(t_top *num, int nb, int index)
{
	t_num	*new;

	if (!num || !nb)
		return (0);
	new = malloc(sizeof(t_num));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->content = nb;
	new->index = index;
	new->next = num->first;
	num->first = new;
	return (0);
}

int	ft_num_addback(t_top *num, int nb, int index)
{
	t_num	*new;
	t_num	*last;

	if (!num || !nb)
		return (0);
	new = malloc(sizeof(t_num));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->content = nb;
	new->index = index;
	new->next = NULL;
	if (num->first == NULL)
	{
		num->first = new;
		return (0);
	}
	last = num->first;
	while (last->next)
		last = last->next;
	last->next = new;
	return (0);
}
