/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:20:54 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 17:40:25 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (d <= s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len-- > 0)
			*d-- = *s--;
	}
	return (dst);
}
