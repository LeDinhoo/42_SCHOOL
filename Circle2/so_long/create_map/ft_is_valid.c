/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:21:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 14:09:09 by hdupuy           ###   ########.fr       */
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

int	ft_is_valid(t_map *map)
{
	map->width = ft_strlen(map->map[0]);
	printf("Hauteur : %d Largeur: %d\n", map->height, map->width);
	printf("C'est un rectangle ? %d\n", ft_is_square(map->map));
	printf("Les murs sont valides ? %d\n", ft_wall_valid(map->map, map->height));
	printf("Les objets sont valides ? %d\n", ft_objects_valid(map));
	printf("Le chemin est valide ? %d\n", ft_path_valid(map));
	return (1);
}
