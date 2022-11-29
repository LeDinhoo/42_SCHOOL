/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:49:58 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 13:40:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wich_type(char type, va_list s_arg)
{
	ssize_t	i;
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	i = 0;
	if (type == 'c')
		i = ft_putchar(va_arg(s_arg, int));
	else if (type == 's')
		i = (ft_putstr(va_arg(s_arg, char *)));
	else if (type == 'i' || type == 'd')
		i = ft_putnbr_printf(va_arg(s_arg, int));
	else if (type == 'u')
		i = ft_putnbr_u(va_arg(s_arg, unsigned int));
	else if (type == 'x')
		i = print_hex(va_arg(s_arg, unsigned int), base);
	else if (type == 'X')
		i = print_hex(va_arg(s_arg, unsigned int), base2);
	else if (type == 'p')
	{
		i = write (1, "0x", 2);
		i += print_hex(va_arg(s_arg, unsigned long long int), base);
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	s_arg;
	size_t	idx;
	ssize_t	count;

	idx = 0;
	count = 0;
	va_start(s_arg, s);
	while (s[idx])
	{
		if (s[idx] == '%' && (s[idx - 1] == '%'))
			count += ft_putchar('%');
		else if (s[idx] == '%' && s[idx + 1])
			count += (ft_wich_type(s[idx + 1], s_arg));
		else if (s[idx] != '%' && s[idx - 1] != '%')
			count += ft_putchar(s[idx]);
		idx++;
	}
	return (count);
}

/*int main(void)
{
	char 	s1[] = " %% ";
	long long int	s2 = 9223372036854775807;

	printf("\n%d\n", ft_printf(s1, s2));
	printf("\n%d\n", printf(s1, s2));
	return (0);
}*/
