/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 10:54:47 by hdupuy           ###   ########.fr       */
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

char	**ft_create_map(void)
{
	int		i;
	int		fd;
	char	*big_line;
	char	**map;

	i = 0;
	big_line = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	while (read(fd, NULL, BUFFER_SIZE) != 0)
		big_line = ft_strjoin(big_line, (get_next_line(fd)));
	map = ft_split(big_line, '\n');
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
