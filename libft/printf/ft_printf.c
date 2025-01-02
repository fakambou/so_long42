/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:11:01 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 21:45:00 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_format(va_list args, const char s)
{
	int	count;

	count = 0;
	if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 'x')
		count += ft_puthex_low(va_arg(args, unsigned int));
	else if (s == 'X')
		count += ft_puthex_upp(va_arg(args, unsigned int));
	else if (s == '%')
		count += ft_putchar('%');
	else if (s == 'u')
		count += ft_uputnbr(va_arg(args, unsigned int));
	else if (s == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_format(args, s[i + 1]);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
// int main(void)
// {
// 	printf("hello my name is %s and i am 19\n","fares");
// 	ft_printf("hello my name is %s and i am 19", "fares");
// }