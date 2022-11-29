/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:20:10 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 09:28:26 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *s, ...);
int				ft_isalpha(int c);
ssize_t			ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr_u(unsigned int n);
void			ft_int_char(int nmb);
int				ft_putnbr_hex(int n, char c);
void			ft_int_hex(int nmb, char c);
int				ft_address_hex(unsigned long long int n, char c);
ssize_t			print_hex(unsigned int n, char *base);
ssize_t			ft_putnbr_printf(int n);


#endif
