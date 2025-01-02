/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:20 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/07 17:55:29 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptrr;

	ptr = (unsigned char *)dest;
	ptrr = (unsigned char *)src;
	while (n--)
	{
		*ptr++ = *ptrr++;
	}
	return (dest);
}
