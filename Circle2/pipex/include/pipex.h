/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 10:47:40 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
// A supprimer
# include <stdio.h>

typedef struct s_cmd_list
{
	char				*cmd;
	char				*cmd_path;
	char				**args;
	int					is_last;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_cmd_tab
{
	char				**cmd;
	char				**cmd_path;
	char				***cmd_args;
}						t_cmd_tab;

typedef struct s_pip
{
	t_cmd_list			*cmd_lst;
	t_cmd_tab			tab;
	char				**path;
	char				*infile;
	char				*outfile;
	int					f1;
	int					f2;
	int					input_fd;
	int					pipe_fd[2];
	int					nb_steps;
}						t_pip;

// file_handling.c
void					open_fd(char *infile, char *outfile, t_pip *pipex);

// command_handling.c
void					split_cmd_arguments(char **argv, int argc,
							t_pip *pipex);
void					add_cmd_to_path(t_pip *pipex, char *full_path);
void					init_new_command(t_pip *pipex, t_cmd_list *new_command,
							int k, int i);

// string_manipulation.c
void					join_cmd(t_pip *pipex, char *cmd);
void					remove_cmd(t_pip *pipex, char *cmd);
int						search_substring(const char *string,
							const char *substring);

// command_parsing.c
void					add_command(t_pip *pipex, t_cmd_list **head);
bool					access_cmd(t_pip *pipex);
void					access_cmd_full(char *command, t_pip *pipex, int index);
t_cmd_list				*create_new_command(t_pip *pipex, int *k, int i);
void					append_command(t_cmd_list **head,
							t_cmd_list *new_command);

// memory_management.c
void					free_arguments(char **args);
void					free_path(t_pip *pipex);
void					free_structure(t_pip *pipex);
void					free_false_cmd(t_pip *pipex, int i);
void					free_cmd_list(t_cmd_list *list);

// path_handling.c
char					*join_path(char *s1, char *s2);
void					get_path(char **env, t_pip *pipex);
void					split_path(char *path, t_pip *pipex);

// error_handling.c
bool					handle_arguments_error(int argc, char **envp);

// command_execution.c
void					process_cmd(t_pip *pipex);

// debugging.c
void					print_args(t_pip *pipex);
void					print_cmd_args(t_pip *pip);

// utility.c
int						check_empty(char **argv);
bool					check_whitespace_only(const char *str);

// pipex.utils.c
int						cmd_numbers(t_cmd_list *cmd);
void					set_last_cmd(t_pip *pip);
int						is_only(t_pip *pip);
void					execute_one_cmd(t_pip *pip);
void					execute_cmd(t_pip *pip, t_cmd_list *current,
							int pipe_fd[2], int i);
void					wait_for_children(t_pip *pip);
void					handle_single_cmd_case(t_pip *pip);
void					iterate_commands(t_pip *pip);
void					pipex(t_pip *pip);

#endif
