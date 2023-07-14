/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/14 14:54:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
#include <dirent.h>



# define PATH_MAX 4096
# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7
# define HEREDOC 8

typedef struct s_switch
{
	char			*substitutedtoken;
	char			*variablename;
	char			*variablevalue;
	int				is_switch;
}					t_switch;

typedef struct s_replace
{
	char			*str;
	char			*str1;
	char			*str2;
	int				len_substr1;
	int				len_substr2;
	int				count;
	char			*resultat;
}					t_replace;

typedef struct s_split
{
	int				start;
	int				end;
	int				length;
	int				in_quotes;
	int				in_simple_quotes;
	int				tokenlength;
}					t_split;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_parser
{
	t_token			*head;
	int				start;
	size_t			end;
	int				in_quotes;
}					t_parser;

typedef struct s_mini
{
	char			*input;
	char			**env;
	struct s_token	*start;
}					t_mini;

// path.c :

void				get_path(t_mini *mini);
// init.c :

void				init_struct(t_mini *mini);
// node_management.c :

void				add_node(t_token **head, char *str, int type);
void				free_list(t_token *head);
// token_identification.c :

int					determine_token_type(const char *str);
char				*substitute_variable_value(char *token, t_split *tkn);
void				add_token_to_list(t_token **head, const char *start,
						int tokenLength, t_split *tkn);
						
// command_processing.c :

void				is_cmd(t_token *current, char **env, int i);
void				update_token_types(t_mini *mini);
// memory_management.c :

void				free_env(t_mini *mini);
// print_helper.c :

void				print_list(t_token *head);

// string_split.c :

t_token				*split_string(const char *str);
void				update_in_quotes(t_parser *parser);

// builtins.c
t_token				*echo_build(t_token *head);

#endif
