/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:01:13 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/03 14:01:45 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_isnum(char *num)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (num[i])
	{
		if (sign > 1)
			return (0);
		if (num[i] == '+' || num[i] == '-')
		{
			i++;
			sign++;
		}
		if (num[i] > 57 || num[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_check_arg(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (ft_isnum(argv[i]) == 0)
			return (0);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	if (ft_check_double(argv) == 0)
		return (0);
	return (1);
}
