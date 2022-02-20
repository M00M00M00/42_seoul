/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:05:37 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 18:32:48 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dict.h"
#include <unistd.h>
int		ft_strlen(char *str);
void	put_str(char *str);

void	put_digit(char now, int jari, t_dict *arr)
{
	if (now == '0')
		return ;
	if (jari / 3 > 0)
		write(1, arr[jari / 3 + 28].value, ft_strlen(arr[jari / 3 + 28].value));
	write(1, " ", 1);
}

void	put1(char prev, char now, t_dict *arr)
{
	if (now == '0')
		return ;
	if (prev == 0)
	{
		put_str(arr[now - '0'].value);
		write(1, " ", 1);
		return ;
	}
	if (prev - '0' == 1)
		return ;
	put_str(arr[now - '0'].value);
	write(1, " ", 1);
}

void	put2(char now, char next, t_dict *arr)
{
	if (now == '0')
		return ;
	else if (now - '0' == 1)
	{
		put_str(arr[10 + (next - '0')].value);
	}
	else
	{
		put_str(arr[20 + (now - '0') - 2].value);
	}
	write(1, " ", 1);
}

void	put0(char now, t_dict *arr)
{
	if (now == '0')
		return ;
	put_str(arr[now - '0'].value);
	write(1, " ", 1);
	put_str("hundred");
	write(1, " ", 1);
}
