/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:01:45 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/04 12:14:56 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_stdin(int i, t_pip *pip)
{
	if (i == 0)
		dup2(pip->f1, STDIN_FILENO);
	if (i == 0 && pip->is_here_doc == 1)
	{
		dup2(pip->here_doc_fd, STDIN_FILENO);
	}
}

void	here_doc(t_pip *pipex, char *limiter)
{
	char	*s1;

	pipex->is_here_doc = 1;
	pipex->here_doc_fd = open("/tmp/.pipex_here_doc",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->here_doc_fd < 0)
		ft_printf("ERROR");
	while (1)
	{
		write(1, "> ", 2);
		s1 = get_next_line(0);
		if (ft_strncmp(s1, limiter, ft_strlen(limiter)) == 0)
		{
			free(s1);
			break ;
		}
		ft_putstr_fd(s1, pipex->here_doc_fd);
		ft_putstr_fd("\n", pipex->here_doc_fd);
		free(s1);
	}
	close(pipex->here_doc_fd);
}
