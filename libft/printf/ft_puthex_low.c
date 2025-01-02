/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:16:35 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:46:26 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned int n)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_low(n / 16);
	ft_putchar(ptr[n % 16]);
	count++;
	return (count);
}
// int main()
// {
// 	ft_puthex_low(250);
// }