/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:24:38 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 12:10:18 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_up_valid(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[0][i])
	{
		i++;
		if (map[0][i] != '1' && map[0][i] != '\0')
			return (0);
	}
	return (1);
}

int	ft_down_valid(char **map, int size)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[size - 1][i])
	{
		i++;
		if (map[size - 1][i] != '1' && map[size - 1][i] != '\0')
			return (0);
	}

	return (1);
}

int	ft_left_valid(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_right_valid(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!map)
		return (0);
	while (map[0][len])
		len++;
	while (map[i])
	{
		if (map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
