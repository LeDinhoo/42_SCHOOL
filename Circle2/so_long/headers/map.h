/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:45:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/20 17:03:38 by hdupuy           ###   ########.fr       */
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

typedef struct s_walls
{
	char	a;
	char	b;
	char	c;
	char	d;
	char	e;
	char	f;
	char	g;
	char	h;
}	t_walls;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void		*ref;
	t_vector	size;
}	t_window;

typedef struct s_image
{
	void		*ref;
	char		*addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_vector	size;
}	t_image;

typedef struct s_player
{
	t_image		py;
	t_vector	pos;
	int			y_dir;
	int			x_dir;
}	t_player;

typedef struct s_sprite
{
	t_image		wall;
	t_image		wall_01;
	t_image		wall_02;
	t_image		wall_03;
	t_image		wall_04;
	t_image		wall_05;
	t_image		wall_06;
	t_image		wall_07;
	t_image		wall_08;
	t_image		wall_09;
	t_image		wall_10;
	t_image		wall_11;
	t_image		wall_12;
	t_image		wall_13;
	t_image		wall_14;
	t_image		wall_15;
	t_image		floor;
	t_image		p_floor;
}	t_sprite;

typedef struct s_program
{
	void		*mlx;
	char		**map;
	t_window	window;
	t_vector	sprite_position;
	t_sprite	sprite;
	t_player	player;
	int			move_speed;
}	t_program;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);

#endif
