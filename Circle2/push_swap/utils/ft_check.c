/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:01:13 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/26 14:04:28 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == ' ' || num[0] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	error_msg(char *msg, char **argv, int is_modified)
{
	ft_putendl_fd(msg, 2);
	if (is_modified && argv != NULL)
		ft_free(argv);
	exit(0);
}

void	ft_check_arg(char **argv, int argc)
{
	int		i;
	long	tmp;
	int		is_modified;

	is_modified = 0;
	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			error_msg("Error", argv, is_modified);
		is_modified = 1;
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]) || ft_is_repeat(tmp, argv, i))
			error_msg("Error", argv, is_modified);
		tmp = ft_atol(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			error_msg("Error", argv, is_modified);
		i++;
	}
}
