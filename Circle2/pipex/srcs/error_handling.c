/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:44 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:16:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_access_error(t_pip *pipex)
{
	free_structure(pipex);
	perror("Access");
	exit(0);
}

void	handle_open_error(t_pip *pipex)
{
	free_structure(pipex);
	perror("Error");
	exit(0);
}
