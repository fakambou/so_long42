/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:45:08 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/10 18:55:49 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (0);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (big[i] == little[0] && ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
