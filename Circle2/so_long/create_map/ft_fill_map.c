/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 12:43:34 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**ft_fill_map(int fd, char **map)
{
	int		x;
	char	*line;

	x = 0;
	while (x < 10)
	{
		line = get_next_line(fd);
		map[x] = line;
		x++;
	}
	return (map);
}

char	*ft_create_bigline(int fd)
{
	char	*line;

	line = NULL;
	while (read(fd, NULL, BUFFER_SIZE) != 0)
		line = ft_strjoin(line, (get_next_line(fd)));
	return (line);
}

char	**ft_create_map(int fd)
{
	char	*map_line;
	char	**map;

	map_line = ft_create_bigline(fd);
	printf("Les objets sont valides ? %d\n", ft_char_valid(map_line));
	map = ft_split(map_line, '\n');
	return (map);
}
