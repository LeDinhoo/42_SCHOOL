/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:55:54 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/16 11:52:19 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

char	**path_arg(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		ft_printf("%s\n", env[i]);
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	path_arg(envp);
	while (argv[i])
		i++;
	return (0);
}
