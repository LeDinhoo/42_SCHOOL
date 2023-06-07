/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/07 17:36:11 by hdupuy           ###   ########.fr       */
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

typedef struct s_pip
{
	char	**path;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*infile;
	char	*outfile;
	int		f1;
	int		f2;
	int		end[2];
}			t_pip;

bool		access_cmd(t_pip *pipex);
bool		open_fd(char *infile, char *outfile, t_pip *pipex);
bool		process_cmd(t_pip *pipex);
char		*join_path(char *s1, char *s2);
int			search_substring(const char *string, const char *substring);
void		free_arguments(char **args);
void		free_path(t_pip *pipex);
void		free_structure(t_pip *pipex);
void		get_path(char **env, t_pip *pipex);
void		handle_access_error(t_pip *pipex);
void		handle_open_error(t_pip *pipex);
void		join_cmd(t_pip *pipex, char *cmd);
void		remove_cmd(t_pip *pipex);
void		split_command_arguments(char *cmd1, char *cmd2, t_pip *pipex);
void		split_path(char *path, t_pip *pipex);

#endif
