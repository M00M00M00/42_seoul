/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:10:18 by mukim             #+#    #+#             */
/*   Updated: 2022/04/19 16:21:27 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_dup(char *s, size_t n)
{
	size_t	i;
	char	*ss;

	i = 0;
	if (n == 0)
		return (0);
	ss = malloc(sizeof(char) * (n + 1));
	if (!ss)
		return (0);
	while (i < n)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

static size_t	count_str(char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str != c && *str != '\0')
				str++;
		}
		while (*str == c && *str != '\0')
			str++;
	}
	return (cnt);
}

static char	**freeall(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char		**ans;
	size_t		i;
	size_t		idx;
	size_t		temp;

	i = 0;
	idx = 0;
	if (!str)
		return (0);
	ans = malloc(sizeof(char *) * (count_str((char *) str, c) + 1));
	if (!ans)
		return (0);
	while (i < count_str((char *) str, c) && str[idx] != '\0')
	{
		while (str[idx] == c)
			idx++;
		temp = idx;
		while (str[idx] != c && str[idx] != '\0')
			idx++;
		ans[i] = n_dup((char *) &str[temp], idx - temp);
		if (!ans[i++])
			return (freeall(ans));
	}
	ans[i] = 0;
	return (ans);
}
