/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:16:52 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/21 14:55:18 by hdupuy           ###   ########.fr       */
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

int	ft_ext_valid(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
	{
		write(1, "Invalid extension !", 20);
		exit (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc != 2)
	{
		write (1, "Erreur de map !", 16);
		return (0);
	}
	prog.map.file = argv[1];
	ft_ext_valid(prog.map.file);
	ft_map_init(&prog.map);
	ft_game_init(&prog);
	ft_free(prog.map.map);
	exit(0);
}
