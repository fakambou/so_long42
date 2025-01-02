/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:13:26 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:46:37 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upp(unsigned int n)
{
	char	*ptr;
	int		count;

	ptr = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_upp(n / 16);
	ft_putchar(ptr[n % 16]);
	count++;
	return (count);
}
// int	main()
// {
// 	ft_puthex_upp(0);
// }
