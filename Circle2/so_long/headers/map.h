/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:45:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/12 15:07:19 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	*file;
	char	**map;
	int		start_y;
	int		start_x;
	int		end_y;
	int		end_x;
	int		height;
	int		width;
	int		objs;
}	t_map;

#endif
