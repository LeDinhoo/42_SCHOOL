/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/29 13:28:04 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	join_cmd(t_pip *pipex)
{
	int		i;
	char	*cmd_find;

	i = 0;
	while (pipex->path[i])
	{
		cmd_find = ft_strjoin(pipex->path[i], "/");
		ft_printf("%s\n", cmd_find);
		i++;
	}
	return (1);
}

int	check_cmd(t_pip *pipex, char **argv)
{
	pipex->cmd1 = argv[2];
	ft_printf("%s\n", pipex->cmd1);
	join_cmd(pipex);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pip	pipex;

	i = -1;
	if (argc != 5)
		return (1);
	get_path(envp, &pipex);
	check_cmd(&pipex, argv);
	argv[i] = NULL;
	return (0);
}
