/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:03:09 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/07 17:56:48 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptrr;

	ptr = (unsigned char *)dest;
	ptrr = (unsigned char *)src;
	if (ptr < ptrr)
	{
		while (n--)
			*ptr++ = *ptrr++;
	}
	if (ptr > ptrr)
	{
		ptr += n;
		ptrr += n;
		while (n--)
		{
			*--ptr = *--ptrr;
		}
	}
	return (dest);
}
