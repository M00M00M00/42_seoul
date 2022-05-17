/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:03 by mukim             #+#    #+#             */
/*   Updated: 2022/04/12 17:34:46 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*n_s;
	size_t	i;

	i = 0;
	n_s = (char *) s;
	while (i < n)
	{
		if (*(unsigned char *)(n_s + i) == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
