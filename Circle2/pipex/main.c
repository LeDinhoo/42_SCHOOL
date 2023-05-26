/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/17 16:18:43 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pip	pipex;

	i = -1;
	if (argc != 5)
		return (1);
	get_path(envp, &pipex);
	while (pipex.path[++i])
		ft_printf("%s\n", pipex.path[i]);
	argv[i] = NULL;
	return (0);
}
