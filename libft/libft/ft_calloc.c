/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:01:09 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/13 23:20:05 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num && size > SIZE_MAX / num)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, (num * size));
	return (ptr);
}
