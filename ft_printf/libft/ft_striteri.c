/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:14:35 by mukim             #+#    #+#             */
/*   Updated: 2022/04/19 14:55:39 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len_s;
	unsigned int	idx;

	if (!s || !f)
		return ;
	len_s = ft_strlen(s);
	idx = 0;
	while (idx < len_s)
	{
		f(idx, &s[idx]);
		idx++;
	}
	return ;
}
