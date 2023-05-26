/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:45:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/26 13:19:54 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# ifndef FRAMES
#  define FRAMES 70000
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
	t_image		obj_00;
	t_image		obj_01;
	t_image		obj_02;
	t_image		obj_03;
	t_image		obj_04;
	t_image		obj_05;
	t_image		obj_06;
	t_image		coin_01;
	t_image		spawn;
	t_image		spawn_01;
	t_image		grass_00;
	t_image		grass_01;
	t_image		grass_02;
	t_image		grass_03;
	t_image		grass_04;
	t_image		grass_05;
	t_image		grass_07;
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
	t_image		wall_16;
	t_image		smoke_00;
	t_image		smoke_01;
	t_image		smoke_02;
	t_image		smoke_03;
	t_image		smoke_04;
	t_image		smoke_05;
	t_image		smoke_06;
	t_image		smoke_07;
	t_image		smoke_08;
	t_image		smoke_09;
	t_image		smoke_10;
	t_image		smoke_11;
	t_image		smoke_12;
	t_image		smoke_13;
	t_image		smoke_14;
	t_image		smoke_15;
	t_image		smoke_16;
	t_image		smoke_17;
	t_image		smoke_18;
	t_image		smoke_19;
	t_image		floor_00;
	t_image		p_floor;
}	t_sprite;

typedef struct s_image_node
{
	t_image				image;
	struct s_image_node	*next;
}	t_image_node;

typedef struct s_program
{
	void			*mlx;
	t_map			map;
	t_image			img;
	t_window		window;
	t_vector		sprite_position;
	t_sprite		sprite;
	t_player		player;
	int				move_speed;
	t_image_node	*g_image_list;
}	t_program;

#endif
