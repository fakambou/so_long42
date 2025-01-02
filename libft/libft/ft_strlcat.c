/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:22:45 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/13 23:13:08 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	while (src[i] && len_dest + 1 < size)
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';
	return (ft_strlen(src + i) + len_dest);
}
// int main(void)
// {
// 	char dest[] = "iheb";
// 	char src[] = "fares";

// 	printf("%zu", ft_strlcat(dest, src, 50));
// 	return 0;
// }