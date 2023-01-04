/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/04 13:02:31 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_fill_map(int fd, char **map, int count)
{
	int		x;
	char	*line;

	x = 0;
	while (x < count)
	{
		line = get_next_line(fd);
		map[x] = line;
		x++;
	}
	return (map);
}

int	main(void)
{
	int		x;
	int		fd;
	int		count;
	char	**map;
	char	*tmp;

	fd = open("maps/test.ber", O_RDONLY);
	count = 0;
	while (read(fd, NULL, BUFFER_SIZE) != 0)
	{
		tmp = get_next_line(fd);
		free(tmp);
		count++;
	}
	close(fd);
	map = malloc(sizeof(char *) * (count + 1));
	map[count + 1] = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	map = ft_fill_map(fd, map, count);
	printf("%d", (ft_is_valid(map, 0, 0)));
	x = -1;
	while (map[++x])
		free(map[x]);
	free(map);
}
