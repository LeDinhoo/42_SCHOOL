/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:20:10 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 13:16:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *s, ...);
int			ft_wich_type(char type, va_list s_arg);
int			ft_isalpha(int c);
int			ft_putstr(char *s);
ssize_t		ft_putnbr_printf(int n);
ssize_t		print_hex(unsigned long long int n, char *base);
ssize_t		ft_putchar(char c);
char		*ft_itoa(long long int n);
size_t		ft_strlen(const char *s);
ssize_t		ft_putnbr_u(unsigned long long int n);

#endif
