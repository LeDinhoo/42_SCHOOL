/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:21:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/06 15:03:08 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_is_square(char **map)
{
	int		i;
	size_t	width;

	i = 0;
	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	while (map[i + 1])
	{
		if (ft_strlen(map[i + 1]) != width)
		{
			write(1, "Map is not rectangle !", 23);
			exit (0);
		}
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
	ft_is_square(map->map);
	if (!ft_wall_valid(map->map, map->height))
	{
		write(1, "Invalid Wall !", 15);
		exit (0);
	}
	if (!ft_objects_valid(map))
	{
		write(1, "Invalid Objects !", 18);
		exit (0);
	}
	if (!ft_path_valid(map))
	{
		write(1, "Invalid path !", 15);
		exit (0);
	}
	return (1);
}
