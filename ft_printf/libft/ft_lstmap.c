/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:05:57 by mukim             #+#    #+#             */
/*   Updated: 2022/04/19 16:26:46 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_node;
	t_list	*n_node;
	t_list	*n_list;

	temp_node = lst;
	n_list = 0;
	while (temp_node)
	{
		n_node = ft_lstnew(f(temp_node->content));
		if (!n_node)
		{
			ft_lstclear(&n_list, del);
			return (0);
		}
		ft_lstadd_back(&n_list, n_node);
		temp_node = temp_node->next;
	}
	n_node = 0;
	return (n_list);
}
