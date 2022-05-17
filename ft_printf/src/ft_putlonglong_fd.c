/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:07:11 by mukim             #+#    #+#             */
/*   Updated: 2022/05/17 16:10:40 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putlonglong_fd(int n, int fd)
{
	long long	l;
	char		c;

	l = (long long) n;
	c = '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putlonglong_fd(l / 10, fd);
		c += l % 10;
		write(fd, &c, 1);
	}
	else
	{
		c += l % 10;
		write(fd, &c, 1);
	}
}
