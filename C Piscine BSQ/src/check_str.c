/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:15:02 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 20:12:50 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	same_length(char *str, int i)
{
	int	length;

	while (*str != '\n' && *str != 0)
	{
		str++;
		i++;
	}
	if (*str == '\n')
		str++;
	length = i;
	while (*str)
	{
		i = 0;
		while (*str != '\n' && *str != 0)
		{
			str++;
			i++;
		}
		if (i != length)
			return (0);
		if (*str == '\n')
			str++;
	}
	return (1);
}

int	right_row_num(char *str, t_map params)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	if (i != params.row_num)
		return (0);
	return (1);
}

int	check_char(char *str, t_map params)
{
	while (*str)
	{
		if (*str != '\n' && *str != params.empty && \
		 *str != params.obs)
			return (0);
		str++;
	}
	return (1);
}

int	check_str(char *str, t_map params)
{
	return (same_length(str, 0) * \
	right_row_num(str, params) * check_char(str, params));
}
