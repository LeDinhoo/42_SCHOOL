/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/16 10:26:34 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	handle_arguments_error(int argc, char **envp)
{
	if (argc < 5)
	{
		ft_printf("Error: Not enough arguments\n");
		return (false);
	}
	if (!envp)
	{
		ft_printf("Error: Environment not available");
		return (false);
	}
	return (true);
}
