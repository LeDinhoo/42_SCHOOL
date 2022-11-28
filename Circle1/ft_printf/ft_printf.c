/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:49:58 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/28 19:23:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wich_type(char type, va_list s_arg)
{
	if (type == 'c')
		ft_putchar(va_arg(s_arg, int));
	else if (type == 's')
		ft_putstr(va_arg(s_arg, char *));
	else if (type == 'i' || type == 'd')
		ft_putnbr(va_arg(s_arg, int));
	else if (type == 'u')
		ft_putnbr_u(va_arg(s_arg, unsigned int));
	else if (type == 'x')
		ft_putnbr_hex(va_arg(s_arg, int), 'a');
	else if (type == 'X')
		ft_putnbr_hex(va_arg(s_arg, int), 'A');
	else if (type == 'p')
	{
		write (1, "0x", 2);
		ft_address_hex(va_arg(s_arg, unsigned long long int), 'a');
	}
	//else
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
		else if (s[idx] && s[idx + 1])
			ft_putchar(s[idx + 1]);
		idx++;
	}
	return (0);
}

int main(void)
{
	char 	s1[] = "%p Adresse du pointeur";
	char	*s2 = "On mange";

	printf("\n%d\n", ft_printf(s1, s2));
	printf("\n%d\n", printf(s1, s2));
	return (0);
}
