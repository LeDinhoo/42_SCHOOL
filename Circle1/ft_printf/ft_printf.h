/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:20:10 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/28 19:04:57 by hdupuy           ###   ########.fr       */
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
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
int				ft_putnbr_u(unsigned int n);
void			ft_int_char(int nmb);
int				ft_putnbr_hex(int n, char c);
void			ft_int_hex(int nmb, char c);
int				ft_address_hex(unsigned long long int n, char c);


#endif
