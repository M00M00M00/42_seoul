/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:10:18 by mukim             #+#    #+#             */
/*   Updated: 2022/03/25 00:17:20 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_str(char *str, char c)
{
	int	cnt;

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

void	allocate_each(char **ans, char *str, char c, int size_of_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str == c)
		str++;
	while (i < size_of_str)
	{
		j = 0;
		while (*str != c && *str != '\0')
		{
			ans[i][j] = *str;
			j++;
			str++;
		}
		while (*str == c)
			str++;
		ans[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char const *str, char c)
{
	char	**ans;
	int		size_of_str;
	int		i;
	int		len_str;

	len_str = ft_strlen(str);
	size_of_str = count_str((char *) str, c);
	ans = malloc(sizeof(char *) * (size_of_str + 1));
	i = 0;
	while (i < size_of_str)
	{
		ans[i] = malloc(sizeof(char) * (len_str + 1));
		i++;
	}
	ans[i] = 0;
	allocate_each(ans, (char *) str, c, size_of_str);
	return (ans);
}
