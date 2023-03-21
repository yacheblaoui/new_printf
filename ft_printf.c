/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:53:21 by yachebla          #+#    #+#             */
/*   Updated: 2023/03/20 12:33:04 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char str, va_list p)
{
	if (str == '%')
		print_putchar('%');
	else if (str == 'c')
		print_putchar(va_arg(p, int));
	else if (str == 's')
		print_putstr(va_arg(p, char *));
	else if (str == 'd' || str == 'i')
		print_putnbr(va_arg(p, int));
	else if (str == 'u')
		print_putnbr(va_arg(p, unsigned int));
	else if (str == 'x')
		print_hexa(va_arg(p, unsigned int), 'l');
	else if (str == 'X')
		print_hexa(va_arg(p, unsigned int), 'u');
	else if (str == 'p')
	{
		print_putstr("0x");
		print_hexa(va_arg(p, unsigned long), 'l');
	}
	else
		print_putchar(str);
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
