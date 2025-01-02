/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:37:43 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/12 21:51:52 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long nb)
{
	int	res;

	res = 0;
	if (nb <= 0)
	{
		nb = -nb;
		res++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = nb_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (nb == 0)
		str[len] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
