/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:45:55 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/13 22:35:46 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static char	*ft_cpy(char **res, const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			res[i] = malloc(len + 1);
			if (res[i] == NULL)
				return (NULL);
			ft_strlcpy(res[i], s - len, len + 1);
			i++;
		}
	}
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	int		mots;
	char	**res;

	if (!s)
		return (NULL);
	mots = ft_count_word(s, c);
	res = malloc(sizeof(char *) * (mots + 1));
	if (!res)
		return (NULL);
	res[mots] = NULL;
	ft_cpy(res, s, c);
	return (res);
}

// int main(void)
// {
// 	char s[] = "fares	le	crack	intersiderale	mew	mew";
// 	char **res = ft_split(s, ' ');
// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// 	free(*res);
// 	return 0;
// }