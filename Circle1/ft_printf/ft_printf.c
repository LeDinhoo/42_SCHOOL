/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:49:58 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/25 17:07:40 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_wich_type(char type, va_list s_arg)
{
	if (type == 'c')
		(ft_putchar(va_arg(s_arg, int)));
	/*else if (type == 's')
	else if (type == 'p')
	else if (type == 'd')
	else if (type == 'i')
	else if (type == 'u')
	else if (type == 'x')
	else if (type == 'X')
	else*/
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	s_arg;
	size_t	idx;

	idx = 0;
	va_start(s_arg, s);
	while (s[idx])
	{
		if (s[idx] == '%' && s[idx + 1])
			ft_wich_type(s[idx + 1], s_arg);
		idx++;
	}
	return (0);
}

int main(void)
{
	char s1[] = "%c Mon caractere";
	char s2 = '2';
	char s3 = '3';
	char s4 = '4';
	char s5 = '5';
	char s6 = '6';

	ft_printf(s1, s2, s3, s4, s5, s6);
	printf(s1, s2, s3, s4, s5, s6);
	return (0);
}
