/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:54:26 by mukim             #+#    #+#             */
/*   Updated: 2022/04/26 18:58:10 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;
	int		idx;

	size = 0;
	idx = 0;
	while (s[idx++])
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	s = (char *) malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ss = malloc(1);
		ss[0] = 0;
		return (ss);
	}
	if (len > (ft_strlen(s) - start))
		ss = (char *)malloc(ft_strlen(s) - start + 1);
	else
		ss = (char *)malloc(len + 1);
	if (!ss)
		return (NULL);
	while (s[start + ++i] && i < len)
		ss[i] = s[start + i];
	ss[i] = 0;
	return (ss);
}

int	find_first_idx(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	while (s1[i])
		i++;
	cp = malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (0);
	i = 0;
	while (s1[i])
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
