/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:51:03 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 16:51:07 by hdupuy           ###   ########.fr       */
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
	printf("\n");
	ft_display_init();
	ft_free(map.map);
	return (1);
}
