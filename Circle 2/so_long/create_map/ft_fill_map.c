/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/04 20:25:41 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_create_map(void)
{
	int		fd;
	char	*big_line;

	big_line = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	while (read(fd, NULL, BUFFER_SIZE) != 0)
		big_line = ft_strjoin(big_line, (get_next_line(fd)));
	printf("%s", big_line);
	return (0);
}
