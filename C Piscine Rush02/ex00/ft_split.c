/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjupa <sangjupa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:46:50 by sangjupa          #+#    #+#             */
/*   Updated: 2022/02/19 15:24:21 by sangjupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_col(char *str, char *charset)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		while (is_in_charset(*str, charset) && *str)
			str++;
		if (!*str)
			return (cnt);
		cnt++;
		while (!is_in_charset(*str, charset) && *str)
			str++;
	}
	return (cnt);
}

char	**make_arr(char *str, char *charset, char **arr, int len)
{
	int		i;
	int		j;
	int		row_len;
	char	*head;

	i = 0;
	while (len--)
	{
		j = 0;
		row_len = 0;
		while (is_in_charset(*str, charset) && *str)
			str++;
		head = str;
		while (!is_in_charset(*str, charset) && *str)
		{
			str++;
			row_len++;
		}
		arr[i] = (char *)malloc(sizeof(char) * row_len + 1);
		while (j < row_len)
			arr[i][j++] = *head++;
		arr[i++][j] = 0;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		col_len;
	char	**arr;

	col_len = ft_col(str, charset);
	arr = (char **)malloc(sizeof(char *) * col_len + 1);
	if (!(arr))
		return (0);
	if (!(make_arr(str, charset, arr, col_len)))
		return (0);
	return (arr);
}
