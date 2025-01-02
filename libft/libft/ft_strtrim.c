/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:38 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/12 21:46:24 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup (s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i])
	{
		while (s1[j] && ft_strchr(set, s1[j]))
			j--;
	}
	trim = ft_substr(s1, i, j - i + 1);
	return (trim);
}
// int main(void)
// {
// 	char s1 [] = "  ***far*es***   ";
// 	char set [] = "* ";
// 	char *res = ft_strtrim(s1, set);
// 	printf("%s", ft_strtrim(s1, set));
// 	free (res);
// }