/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:31 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/19 16:19:14 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}
// int main()
// {
// 	t_list *node1 = ft_lstnew("node1");
// 	node1 -> next = NULL;
// 	printf("dernier element de la liste : %s", (char *)ft_lstlast(node1));
// 	free (node1);
// }