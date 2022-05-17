/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:10:37 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 16:07:21 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*n_s;
	char	*temp;

	n_s = (char *) s;
	temp = 0;
	if (c == '\0')
	{
		while (*n_s)
			n_s++;
		return (n_s);
	}
	while (*n_s)
	{
		if (*n_s == (char) c)
			temp = n_s;
		n_s++;
	}
	return (temp);
}
