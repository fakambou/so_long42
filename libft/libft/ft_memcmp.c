/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:24:57 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/10 20:05:47 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptrr;
	size_t			i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (-1);
	ptr = (unsigned char *)s1;
	ptrr = (unsigned char *)s2;
	i = 0;
	while (i < n && ptr[i] == ptrr[i])
		i++;
	if (i == n)
		return (0);
	return (ptr[i] - ptrr[i]);
}
// int main(void)
// {
// 	char s1 [] = "fares";
// 	char s2 [] =  "kamboui";
// 	printf("%d",ft_memcmp(s1, s2, 0));
// }