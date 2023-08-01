/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:42:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/04 11:46:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_fd(char *infile, char *outfile, t_pip *pipex)
{
	if (pipex->is_here_doc == 1)
	{
		pipex->f1 = open("/tmp/.pipex_here_doc", O_RDONLY);
		pipex->f2 = open(outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	else
	{
		pipex->f1 = open(infile, O_RDONLY);
		pipex->f2 = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (pipex->f1 == -1)
	{
		perror("Invalid file descriptor");
	}
	if (pipex->f2 == -1)
	{
		free_structure(pipex);
		ft_printf("%s: ", outfile);
		perror("Invalid file descriptor");
		exit(0);
	}
}
