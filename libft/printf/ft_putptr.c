/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:37:00 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/21 19:48:41 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long p)
{
	int	count;

	count = 0;
	if (p == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex_ptr(p);
	return (count);
}
