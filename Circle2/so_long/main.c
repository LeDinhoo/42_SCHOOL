/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:16:52 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 13:14:24 by hdupuy           ###   ########.fr       */
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

int	main(void)
{
	t_map	map;

	ft_create_map(&map);
	ft_map_info(&map);
	ft_is_valid(&map);
	// ft_display_init();
	printf("%d, %d, %d, %d, %d, %d, %d\n", map.start_y, map.start_x, map.end_y, map.end_x, map.height, map.width, map.objs);
	ft_free(map.map);
	return (1);
}
