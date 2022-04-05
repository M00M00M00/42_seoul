/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:47:32 by mukim             #+#    #+#             */
/*   Updated: 2022/04/04 18:01:19 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ls;

	ls = (t_list *) malloc(sizeof(*ls));
	if (!ls)
		return (0);
	ls -> content = content;
	ls -> next = 0;
	return (ls);
}
