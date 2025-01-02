/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:31:38 by fakambou          #+#    #+#             */
/*   Updated: 2024/11/17 20:16:25 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
// int main()
// {
//     t_list *node1 = ft_lstnew("node 1");
//     t_list *node2 = ft_lstnew("node 2");
//     t_list *node3 = ft_lstnew("node 3");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     printf("Taille de la liste : %d\n", ft_lstsize(node1));

//     free(node1);
//     free(node2);
//     free(node3);
// }