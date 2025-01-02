/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:10:57 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/17 20:14:43 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&tmp, (*del));
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst -> next;
	}
	return (res);
}
