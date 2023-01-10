/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/10 13:35:29 by hdupuy           ###   ########.fr       */
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

char		*get_next_line(int fd);
int			ft_is_valid(char **map);
char		**ft_fill_map(int fd, ssize_t nb_line, char **map);
char		**ft_create_map(void);
int			ft_up_valid(char **map);
int			ft_down_valid(char **map, int size);
int			ft_left_valid(char **map);
int			ft_right_valid(char **map);
int			ft_char_valid(char **map);
int			ft_path_valid(char **map);
int			ft_number_lines(int fd);
int			ft_display_init(void);

#endif
