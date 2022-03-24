/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:36:40 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 17:46:46 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	unsigned char	*hay;
	unsigned char	*need;

	i = 0;
	hay = (unsigned char *) haystack;
	need = (unsigned char *) needle;
	if (*need == '\0')
		return (hay);
	while (hay[i] && i < (int) len)
	{
		j = 0;
		while (hay[i + j] == need[j] && need[j])
			j++;
		if (need[j] == '\0')
			return (hay + i);
		i++;
	}
	return (0);
}
