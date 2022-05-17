/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:03:10 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 16:07:50 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*n_s;

	n_s = (char *) s;
	if (c == '\0')
	{
		while (*n_s)
			n_s++;
		return (n_s);
	}
	while (*n_s)
	{
		if (*n_s == (char) c)
			return (n_s);
		n_s++;
	}
	return (0);
}
