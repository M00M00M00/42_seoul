/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:36:40 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 22:56:49 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*need;

	i = 0;
	hay = (char *) haystack;
	need = (char *) needle;
	if (*need == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == need[j] && need[j] && j + i < len)
			j++;
		if (need[j] == '\0')
			return (hay + i);
		i++;
	}
	return (0);
}
