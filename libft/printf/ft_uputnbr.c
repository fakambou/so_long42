/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:13:34 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:09:57 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchar((n % 10 + '0'));
	return (count);
}
