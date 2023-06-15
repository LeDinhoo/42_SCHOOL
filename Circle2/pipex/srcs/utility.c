/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:21:47 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/15 18:28:09 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_whitespace_only(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
		{
			return (true);
		}
		str++;
	}
	return (false);
}

int	check_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
			return (ft_printf("Error empty arguments", 1));
		i++;
	}
	return (0);
}
