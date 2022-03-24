/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:03 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 16:26:55 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*n_s;
	size_t	i;

	i = 0;
	n_s = (char *) s;
	if (c == '\0')
	{
		while (*n_s && i++ < n)
			n_s++;
		if (i == n)
			return (0);
		return (n_s);
	}
	while (*n_s && i++ < n)
	{
		if (*n_s == (char) c)
			return (n_s);
		n_s++;
	}
	return (0);
}
