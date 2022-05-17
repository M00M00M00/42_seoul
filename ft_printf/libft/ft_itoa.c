/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:25:19 by mukim             #+#    #+#             */
/*   Updated: 2022/04/04 17:38:06 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nlen(int n)
{
	int			len_n;
	long long	l_n;

	len_n = 0;
	l_n = n;
	if (n < 0)
		l_n *= -1;
	if (l_n == 0)
		return (1);
	else
	{
		while (l_n > 0)
		{
			l_n = l_n / 10;
			len_n += 1;
		}
	}
	return (len_n);
}

char	*ft_itoa(int n)
{
	int			len_n;
	long long	l_n;
	int			idx;
	char		*s;

	len_n = nlen(n);
	l_n = n;
	idx = 0;
	if (n < 0)
	{
		l_n *= -1;
		len_n += 1;
	}
	s = (char *) malloc(sizeof(char) * (len_n + 1));
	if (!s)
		return (0);
	if (n < 0)
		s[idx++] = '-';
	s[len_n] = 0;
	while (idx < len_n)
	{
		s[--len_n] = l_n % 10 + '0';
		l_n /= 10;
	}
	return (s);
}
