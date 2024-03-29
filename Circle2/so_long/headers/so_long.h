/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/04/18 10:16:31 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "map.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

char		**ft_create_map(t_map *map);
char		**ft_fill_map(int fd, ssize_t nb_line, char **map);
char		*get_next_line(int fd);
int			ft_all_sprite(t_sprite *sprite, t_program *prog, t_player *p);
int			ft_char_valid(char **map);
int			ft_check_all(t_program *p);
int			ft_check_down(void *param);
int			ft_check_left(void *param);
int			ft_check_right(void *param);
int			ft_check_up(void *param);
int			ft_count_objs(char **map);
int			ft_down_valid(char **map, int size);
int			ft_end(t_program *p);
int			ft_finish(t_program *p);
int			ft_game_init(t_program *prog);
int			ft_init_wall(t_walls *wall);
int			ft_is_valid(t_map *map);
int			ft_left_valid(char **map);
int			ft_map_info(t_map *map);
int			ft_map_start(t_program *prog);
int			ft_number_lines(int fd);
int			ft_objects_valid(t_map *map);
int			ft_path_valid(t_map *map);
int			ft_put_exit(t_program *p, t_sprite *s, char **map);
int			ft_put_floor(t_program *p, t_sprite *s);
int			ft_put_grass(t_program *p, t_sprite *s);
int			ft_put_object(t_sprite *s, t_program *p, char **map);
int			ft_put_spawn(t_program *p, t_sprite *s, t_vector pos_p);
int			ft_put_wall(t_sprite *s, t_program *p, char **map, t_vector pos);
int			ft_release(int key, void *param);
int			ft_right_valid(char **map);
int			ft_smoke_anim(void *param);
int			ft_smoke_anim1(t_program *p, int y, int x, int frame);
int			ft_smoke_anim2(t_program *p, int y, int x, int frame);
int			ft_smoke_anim3(t_program *p, int y, int x, int frame);
int			ft_smoke_anim4(t_program *p, int y, int x, int frame);
int			ft_smoke_anim5(t_program *p, int y, int x, int frame);
int			ft_sprite_grass(t_sprite *sprite, t_program *prog);
int			ft_sprite_map(t_sprite *s, t_program *p, t_map *map);
int			ft_sprite_obj(t_program *p, t_sprite *s);
int			ft_sprite_obj2(t_program *p, t_sprite *s, int frame);
int			ft_sprite_obj3(t_program *p, t_sprite *s, int frame);
int			ft_sprite_smoke(t_sprite *sprite, t_program *prog);
int			ft_sprite_wall(t_sprite *sprite, t_program *prog);
int			ft_up_valid(char **map);
int			ft_update_map(t_sprite *s, t_program *p, char **map);
int			ft_wall_floor(t_program *p, t_sprite *s, char **map, t_vector pos);
int			ft_wall_valid(char **map, int size);
int			ft_wich_wall(char **map, t_vector pos, t_walls *wall);
int			key_press(int key, void *param);
int			move_sprite_and_redraw(void *param);
int			put_wall_1(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_2(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_3(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_4(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_5(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_6(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_7(t_sprite *s, t_program *p, char **map, t_vector pos);
int			put_wall_8(t_sprite *s, t_program *p, char **map, t_vector pos);
t_image		ft_new_sprite(void *mlx, char *path, t_program *t_program);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
void		*ft_free(t_program *p);
void		ft_free_images(t_program *p);
void		ft_map_init(t_map *map);
void		*ft_free_error(t_map *map);

#endif
