/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:53:24 by yachebla          #+#    #+#             */
/*   Updated: 2023/03/18 13:05:51 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	print_putchar(char c);
void	print_putstr(char *str);
void	print_putnbr(long x);
int		g_r;
void	print_hexa(unsigned long n, char c);
int		ft_printf(const char *format, ...);

#endif
