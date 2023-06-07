/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:23:40 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/07 17:29:15 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	open_fd(char *infile, char *outfile, t_pip *pipex)
{
	pipex->f1 = open(infile, O_RDONLY);
	if (pipex->f1 == -1)
	{
		perror("Error opening infile");
		return (close(pipex->f1), false);
	}
	pipex->f2 = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->f2 == -1)
	{
		perror("Error opening outfile");
		return (close(pipex->f2), false);
	}
	return (true);
}