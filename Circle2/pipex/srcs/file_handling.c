/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:42:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 10:22:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_fd(char *infile, char *outfile, t_pip *pipex)
{
	pipex->f1 = open(infile, O_RDONLY);
	if (pipex->f1 == -1)
	{
		free_structure(pipex);
		perror("Error");
		exit(0);
	}
	pipex->f2 = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->f2 == -1)
	{
		free_structure(pipex);
		ft_printf("%s: ", outfile);
		perror("");
		exit(0);
	}
}
