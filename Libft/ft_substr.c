/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:33:39 by mukim             #+#    #+#             */
/*   Updated: 2022/03/25 00:06:28 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	m_size(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((unsigned int) i >= start)
			j++;
		i++;
	}
	if (j < len)
		len = j;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = m_size(s, start, len);
	s1 = (char *) malloc(sizeof(*s) * (len + 1));
	if (!s1)
		return (0);
	while (s[i])
	{
		if ((unsigned int) i >= start && j < len)
			s1[j++] = s[i];
		i++;
	}
	s1[j] = '\0';
	return (s1);
}
