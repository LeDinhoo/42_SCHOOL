/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 12:46:00 by hdupuy           ###   ########.fr       */
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

char		*get_next_line(int fd);
int			ft_is_valid(char **map);
char		**ft_fill_map(int fd, char **map);
char		**ft_create_map(int fd);
int			ft_up_valid(char **map);
int			ft_down_valid(char **map, int size);
int			ft_left_valid(char **map);
int			ft_right_valid(char **map);
int			ft_char_valid(char *map);

#endif
