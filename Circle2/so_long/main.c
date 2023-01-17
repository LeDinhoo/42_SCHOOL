/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:16:52 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/17 17:09:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	*ft_free(char **map)
{
	ssize_t	idx;

	idx = 0;
	while (map[idx])
		idx++;
	while (idx > 0)
	{
		idx--;
		free(map[idx]);
	}
	free(map);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write (1, "Erreur de map !", 16);
		return (0);
	}
	map.file = argv[1];
	ft_map_init(&map);
	int b = 0;
	while (map.map[b])
		printf("%s\n", map.map[b++]);
	ft_display_init(&map);
	// ft_free(map.map);
	return (0);
}
