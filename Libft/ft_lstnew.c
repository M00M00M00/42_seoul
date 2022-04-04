/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:47:32 by mukim             #+#    #+#             */
/*   Updated: 2022/04/04 17:54:12 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ls;
	void	*c;

	c = (void *) malloc(sizeof(content));
	if (!c)
		return (0);
	c = content;
	ls -> content = c;
	ls -> next = 0;
	return (ls);
}
