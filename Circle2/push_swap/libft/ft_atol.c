/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:55:30 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/11 16:55:42 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char	*str)
{
	long long	negatif;
	long long	resultat;

	negatif = 0;
	resultat = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			negatif++;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultat = resultat * 10 + (*str - '0');
		str++;
	}
	if ((negatif % 2) == 1)
		return (-resultat);
	else
		return (resultat);
}
