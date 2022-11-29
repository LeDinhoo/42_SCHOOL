/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:10:58 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 09:09:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// int	ft_putnbr_u(unsigned int n)
// {
// 	if (n > 9)
// 	{
// 		ft_putnbr_u(n / 10);
// 		ft_putnbr_u(n % 10);
// 	}
// 	else
// 	{
// 		ft_int_char(n);
// 	}
// 	return (0);
// }

// void	ft_int_hex(int nmb, char c)
// {
// 	char	*base_min;
// 	char	*base_maj;

// 	base_min = "0123456789abcdef";
// 	base_maj = "0123456789ABCDEF";
// 	if (c == 'a')
// 		write (1, &base_min[nmb], 1);
// 	else if (c == 'A')
// 		write (1, &base_maj[nmb], 1);
// }

// int	ft_putnbr_hex(int n, char c)
// {
// 	if (n == -2147483648)
// 	{
// 		write (1, "80000000", 8);
// 		return (0);
// 	}
// 	else if (n < 0)
// 	{
// 		ft_putnbr_hex(n * -1, c);
// 	}
// 	else if (n > 16)
// 	{
// 		ft_putnbr_hex(n / 16, c);
// 		ft_putnbr_hex(n % 16, c);
// 	}
// 	else
// 	{
// 		ft_int_hex(n, c);
// 	}
// 	return (0);
// }

// int	ft_address_hex(unsigned long long int n, char c)
// {
// 	if (n > 16)
// 	{
// 		ft_address_hex(n / 16, c);
// 		ft_address_hex(n % 16, c);
// 	}
// 	else
// 	{
// 		ft_int_hex(n, c);
// 	}
// 	return (0);
// }


ssize_t	print_hex(unsigned int n, char *base)
{
	char	nb_str[9];
	char	*nb_str_ptr;

	if (n == 0)
		return (write(1, "0", 1));
	nb_str[8] = '\0';
	nb_str_ptr = &nb_str[7];
	while (n)
	{
		*nb_str_ptr-- = base[n % 16];
		n /= 16;
	}
	nb_str_ptr++;
	return (write(1, nb_str_ptr, ft_strlen(nb_str)));
}
