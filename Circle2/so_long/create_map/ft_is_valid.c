/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:21:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 13:23:55 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_is_square(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i + 1])
	{
		if ((ft_strlen(map[i]) != (ft_strlen(map[i + 1]))))
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_height(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int	ft_wall_valid(char **map, int size)
{
	if (!map)
		return (0);
	if (ft_up_valid(map))
		if (ft_down_valid(map, size))
			if (ft_left_valid(map))
				if (ft_right_valid(map))
					return (1);
	return (0);
}

int	ft_is_valid(char **map)
{
	int	map_height;
	int	map_width;

	map_height = ft_map_height(map);
	map_width = ft_strlen(map[0]);
	printf("Hauteur : %d Largeur: %d\n", map_height, map_width);
	printf("C'est un rectangle ? %d\n", ft_is_square(map));
	printf("Les murs sont valides ? %d\n", ft_wall_valid(map, map_height));
	ft_path_valid(map);
	return (1);
}
