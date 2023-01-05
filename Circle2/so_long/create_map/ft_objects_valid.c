/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:30:06 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 12:34:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_char_valid(char *map)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != '\0' && map[i] != '\n')
			return (0);
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			e++;
		if (p > 1 || e > 1)
			return (0);
		i++;
	}
	return (1);
}
