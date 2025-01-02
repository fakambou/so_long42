/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:52:24 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/10 19:45:49 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
// int	main(void)
// {
// 	char	*test = "a b c";
// 	char	*dest = ft_strchr(test, 'c');
// 	if (dest == NULL)
// 	{
// 		printf("strchr returned NULL\n");
// 		return 1;
// 	}
//     printf("strchr(\"%s\", '%c') returned %s\n", test, 'c', dest);
// }
