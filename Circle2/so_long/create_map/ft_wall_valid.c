/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:24:38 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/31 08:08:49 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_wall_valid(char **map, int size)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (map[0][len])
		len++;
	while (i < size)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1' || map[size - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
