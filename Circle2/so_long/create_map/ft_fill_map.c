/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:31:29 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/10 10:35:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**ft_fill_map(int fd, ssize_t nb_line, char **map)
{
	int		y;

	y = 0;
	map = malloc(sizeof(char *) * nb_line + 1);
	if (!map)
		return (free(map), NULL);
	while (nb_line > 0)
	{
		map[y] = get_next_line(fd);
		nb_line--;
		y++;
	}
	return (map);
}

int	ft_number_lines(int fd)
{
	int		count;
	char	c;

	count = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

char	**ft_create_map(void)
{
	int			fd;
	ssize_t		nb_lines;
	char		**map;

	map = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	nb_lines = ft_number_lines(fd);
	close(fd);
	fd = open("maps/test.ber", O_RDONLY);
	map = ft_fill_map(fd, nb_lines, map);
	close(fd);
	printf("Les objets sont valides ? %d\n", ft_char_valid(map));
	return (map);
}
