/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:10:58 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 13:15:16 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_hex(unsigned long long int n, char *base)
{
	char	nb_str[17];
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
	return (write(1, nb_str_ptr, ft_strlen(nb_str_ptr)));
}
