/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:20:54 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 15:20:07 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	if (d <= s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len-- > 0)
			*d-- = *s--;
	}
	return (dst);
}
