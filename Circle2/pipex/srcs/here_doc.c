/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:01:45 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 18:20:17 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_here_doc(char *limiter)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s2 = ft_calloc(sizeof(char *), 1);
	while (1)
	{
		write(1, "> ", 2);
		s1 = get_next_line(0);
		if (!s1 || ft_strcmp(s1, limiter) == 0)
			break ;
		s3 = ft_strdup(s2);
		if (!s3)
			ft_printf("ERROR");
		free(s2);
		s2 = ft_strjoin(s3, s1);
		if (!s2)
			ft_printf("ERROR");
	}
	free(s1);
	return (s2);
}

void	here_doc(t_pip *pipex, char *limiter)
{
	char	*s1;

	pipex->is_here_doc = 1;
	s1 = get_here_doc(limiter);
	if (!s1)
		ft_printf("ERROR");
	pipex->here_doc_fd = open("/tmp/.pipex_here_doc",
		O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	if (pipex->here_doc_fd < 0)
		ft_printf("ERROR");
	ft_putstr_fd(s1, pipex->here_doc_fd);
	free(s1);
	close(pipex->here_doc_fd);
	pipex->here_doc_fd = open("/tmp/.pipex_here_doc", O_RDONLY);
	if (pipex->here_doc_fd < 0)
		ft_printf("ERROR");
	if (dup2(pipex->here_doc_fd, 0) == -1)
		ft_printf("ERROR");
	if (close(pipex->here_doc_fd) == -1)
		ft_printf("ERROR");
}
