/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:09:42 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 23:12:43 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	int		i;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	while (*dst)
		dst++;
	if (len_dst < dstsize - 1 && dstsize > 0)
	{
		while (*src && i++ + len_dst + 1 < dstsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len_dst + len_src);
}
