/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:45:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/17 16:21:10 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window {
	void		*ref;
	t_vector	size;
}	t_window;

typedef struct s_image {
	void		*ref;
	char		*addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_vector	size;
}	t_image;

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}	t_program;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);

#endif
