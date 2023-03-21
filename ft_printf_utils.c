/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:45:59 by yachebla          #+#    #+#             */
/*   Updated: 2023/03/20 11:58:34 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_putchar(char x)
{
	write (1, &x, 1);
	g_r++;
}

void	print_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		print_putstr("(null)");
		return ;
	}
	while (str[i])
	{
		print_putchar(str[i]);
		i++;
	}
}

void	print_putnbr(long x)
{
	if (x < 0)
	{
		print_putchar('-');
		print_putnbr(x * (-1));
	}
	else if (x >= 10)
	{
		print_putnbr(x / 10);
		print_putchar(x % 10 + '0');
	}
	else
	{
		print_putchar(x + '0');
	}
}

void	print_hexa(unsigned long n, char c)
{
	char	*base;

	if (c == 'l')
		base = "0123456789abcdef";
	if (c == 'u')
		base = "0123456789ABCDEF";
	if (16 <= n)
		print_hexa(n / 16, c);
	print_putchar(base[n % 16]);
}
