/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:27:01 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmd_tab
{
	char		**cmd;
	char		**cmd_path;
	char		***cmd_args;
}				t_cmd_tab;

typedef struct s_pip
{
	t_cmd_tab	tab;
	char		**path;
	char		*infile;
	char		*outfile;
	int			f1;
	int			f2;
}				t_pip;

// file_handling.c
bool			open_fd(char *infile, char *outfile, t_pip *pipex);

// command_handling.c
void			split_cmd_arguments(char **argv, int argc, t_pip *pipex);
void			add_cmd_to_path(t_pip *pipex, char *full_path);

// string_manipulation.c
void			join_cmd(t_pip *pipex, char *cmd);
void			remove_cmd(t_pip *pipex, char *cmd);
int				search_substring(const char *string, const char *substring);

// command_parsing.c
bool			access_cmd(t_pip *pipex);
void			access_cmd_full(char *command, t_pip *pipex, int index);

// memory_management.c
void			free_arguments(char **args);
void			free_path(t_pip *pipex);
void			free_structure(t_pip *pipex);
void			free_false_cmd(t_pip *pipex, int i);

// path_handling.c
char			*join_path(char *s1, char *s2);
void			get_path(char **env, t_pip *pipex);
void			split_path(char *path, t_pip *pipex);

// error_handling.c
void			handle_access_error(t_pip *pipex);
void			handle_open_error(t_pip *pipex);

// command_execution.c
void			process_cmd(t_pip *pipex);

// debugging.c
void			print_args(t_pip *pipex);

// utility.c
int				check_empty(char **argv);
bool			check_whitespace_only(const char *str);

#endif
