/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:03 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 15:28:52 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_total_size(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (sep[j++])
		cnt++;
	cnt *= size - 1;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			cnt++;
		i++;
	}
	return (cnt + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*str_temp;
	int		i;
	int		j;

	i = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char));
		return (str);
	}
	str = malloc(sizeof(char) * find_total_size(size, strs, sep));
	str_temp = str;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			*str++ = strs[i][j++];
		j = 0;
		if (i++ != size - 1)
			while (sep[j])
				*str++ = sep[j++];
	}
	*str = '\0';
	return (str_temp);
}
