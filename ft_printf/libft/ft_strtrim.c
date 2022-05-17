/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:20:10 by mukim             #+#    #+#             */
/*   Updated: 2022/04/19 14:52:50 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*s;
	int		idx;

	front = 0;
	if (!s1 || !set)
		return (0);
	back = ft_strlen(s1);
	idx = 0;
	while (s1[front] && is_in(s1[front], set))
		front++;
	while (back > front && is_in(s1[back - 1], set))
		back--;
	s = (char *) malloc(sizeof(*s1) * (back - front + 1));
	if (!s)
		return (0);
	while (front < back)
		s[idx++] = s1[front++];
	s[idx] = '\0';
	return (s);
}
