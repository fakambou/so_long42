/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:10:39 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/16 20:53:02 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
// int main(void)
// {
// 	char *str = "nouvelle notion";
// 	t_list *node = ft_lstnew(str);

// 	if(node)
// 		printf("%s",(char *)node -> content);
// 	free(node);
// }