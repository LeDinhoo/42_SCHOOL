/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:01:13 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/15 16:41:24 by hdupuy           ###   ########.fr       */
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

void	error_msg2(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	error_msg(char *msg, char **argv)
{
	ft_putendl_fd(msg, 2);
	if (argv != NULL)
		ft_free(argv);
	exit(0);
}

void	ft_check_arg(char **argv, int argc)
{
	int		i;
	long	tmp;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			error_msg("Error", argv);
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]) || ft_is_repeat(tmp, argv, i))
			error_msg("Error", argv);
		tmp = ft_atol(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			error_msg("Error", argv);
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}
