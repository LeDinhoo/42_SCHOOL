/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/25 11:44:46 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "map.h"

char		*get_next_line(int fd);
int			ft_is_valid(t_map *map);
char		**ft_fill_map(int fd, ssize_t nb_line, char **map);
char		**ft_create_map(t_map *map);
int			ft_up_valid(char **map);
int			ft_down_valid(char **map, int size);
int			ft_left_valid(char **map);
int			ft_right_valid(char **map);
int			ft_char_valid(char **map);
int			ft_path_valid(t_map *map);
int			ft_number_lines(int fd);
int			ft_game_init(t_map *map);
int			ft_map_info(t_map *map);
int			ft_wall_valid(char **map, int size);
int			ft_count_objs(char **map);
int			ft_objects_valid(t_map *map);
void		ft_map_init(t_map *map);
int			ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p);
t_image		ft_new_sprite(void *mlx, char *path);
int			move_sprite_and_redraw(void *param);
int			ft_sprite_map(t_sprite *s, t_program *p, char **map);
int			key_press(int key, void *param);
int			ft_release(int key, void *param);
int			ft_check_right(void *param);
int			ft_check_up(void *param);
int			ft_check_left(void *param);
int			ft_check_down(void *param);
int			ft_put_grass(t_program *p, t_sprite *s);
int			ft_put_floor(t_program *p, t_sprite *s);

#endif
