/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:53:21 by yachebla          #+#    #+#             */
/*   Updated: 2023/03/18 13:59:08 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char str, va_list p)
{
	if (str == '%')
		print_putchar('%');
	if (str == 'c')
		print_putchar(va_arg(p, int));
	if (str == 's')
		print_putstr(va_arg(p, char *));
	if (str == 'd' || str == 'i')
		print_putnbr(va_arg(p, int));
	if (str == 'u')
		print_putnbr(va_arg(p, unsigned int));
	if (str == 'x')
		print_hexa(va_arg(p, unsigned int), 'l');
	if (str == 'X')
		print_hexa(va_arg(p, unsigned int), 'u');
	if (str == 'p')
	{
		print_putstr("0x");
		print_hexa(va_arg(p, unsigned long), 'l');
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	p;

	i = 0;
	va_start(p, str);
	g_r = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (g_r);
			print(str[i], p);
		}
		else if (str[i] == '\n')
			print_putchar('\n');
		else
			print_putchar(str[i]);
		i++;
	}
	va_end(p);
	return (g_r);
}
