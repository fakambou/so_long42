/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:52:06 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/17 20:14:16 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	if (*lst)
	{
		list = *lst;
		while (list)
		{
			temp = list -> next;
			ft_lstdelone(list, del);
			list = temp;
		}
		*lst = NULL;
	}
}
