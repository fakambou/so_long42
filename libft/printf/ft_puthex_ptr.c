/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:31 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 20:23:50 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(unsigned long long n)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	ft_putchar(ptr[n % 16]);
	count++;
	return (count);
}
