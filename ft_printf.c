/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:53:21 by yachebla          #+#    #+#             */
/*   Updated: 2023/03/17 17:40:12 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char format, va_list ptr)
{
	if (format == '%')
		print_putchar('%');
	if (format == 'c')
		print_putchar(va_arg(ptr, int));
	if (format == 's')
		print_putstr(va_arg(ptr, char *));
	if (format == 'd' || format == 'i')
		print_putnbr(va_arg(ptr, int));
	if (format == 'u')
		print_putnbr(va_arg(ptr, unsigned int));
	if (format == 'x')
		print_hexa(va_arg(ptr, unsigned int), 'l');
	if (format == 'X')
		print_hexa(va_arg(ptr, unsigned int), 'u');
	if (format == 'p')
	{
		print_putstr("0x");
		print_hexa(va_arg(ptr, unsigned long), 'l');
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ptr;

	i = 0;
	va_start(ptr, format);
	g_r = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (g_r);
			print(format[i], ptr);
		}
		else if (format[i] == '\n')
			print_putchar('\n');
		else
			print_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (g_r);
}