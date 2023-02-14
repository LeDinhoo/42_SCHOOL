/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:06:41 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/14 11:26:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

long long int	ft_atoi(char *str)
{
	long long int	result;
	int				countsign;

	result = 0;
	countsign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			countsign = countsign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result != ((result * 10 + (*str - '0')) / 10))
			return ((int)ft_overflow(countsign));
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * countsign);
}
