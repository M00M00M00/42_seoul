/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:09:42 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 15:35:01 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	int		i;

	i = 0;
	len_dst = find_len(dst);
	len_src = find_len((char *) src);
	if (len_dst > dstsize)
		return (len_src + dstsize);
	while (*dst)
		dst++;
	while (*src && i++ + len_dst + 1 < dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (len_dst + len_src);
}
