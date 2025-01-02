/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:51:44 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:39:25 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr("-2147483648");
		return (count);
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			count += ft_putnbr(n / 10);
		}
		count += ft_putchar((n % 10 + '0'));
	}
	return (count);
}
// int main()
// {
// 	ft_putnbr(-2147483648);
// }
