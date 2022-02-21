/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:39 by mukim             #+#    #+#             */
/*   Updated: 2022/02/22 00:56:18 by moo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/map.h"

int	is_match(char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	allocate_each(char **ans, char *str, char *charset, int size_of_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_match(str, charset))
		str++;
	while (i < size_of_str)
	{
		j = 0;
		while (!is_match(str, charset) && *str != '\0')
		{
			ans[i][j] = *str;
			j++;
			str++;
		}
		while (is_match(str, charset))
			str++;
		ans[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char *charset, int col_num, int row_num)
{
	char	**ans;
	int		i;

	ans = malloc(sizeof(char *) * (row_num + 1));
	i = 0;
	while (i < row_num)
	{
		ans[i] = malloc(sizeof(char) * (col_num + 1));
		i++;
	}
	ans[i] = 0;
	allocate_each(ans, str, charset, row_num);
	return (ans);
}
