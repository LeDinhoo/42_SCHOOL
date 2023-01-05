/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:21:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 08:44:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_is_valid(char **map, int x, int y)
{
	if (map[x][y] == '1')
		ft_is_valid(map, x, (y + 1));
	if (map[x][y] == '\n')
		printf("Line is valid\n");
	if (map[x][y] != '1')
		return (0);
	return (1);
}