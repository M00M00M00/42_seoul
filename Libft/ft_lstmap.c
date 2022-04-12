/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:05:57 by mukim             #+#    #+#             */
/*   Updated: 2022/04/12 15:26:38 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;
	t_list	*n_node;

	temp = lst;
	node = 0;
	if (!lst || !f || !del)
		return (0);
	while (temp)
	{
		n_node = ft_lstnew(f(lst->content));
		if (!n_node)
		{
			ft_lstclear(&n_node, del);
			return (0);
		}
		ft_lstadd_back(&node, n_node);
		temp = temp->next;
	}
	n_node = 0;
	return (node);
}
