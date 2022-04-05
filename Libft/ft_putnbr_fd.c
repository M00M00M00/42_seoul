/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:28:58 by mukim             #+#    #+#             */
/*   Updated: 2022/04/04 17:33:41 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	l;
	char		c;

	l = n;
	c = '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		c += l % 10;
		write(fd, &c, 1);
	}
	else
	{
		c += l % 10;
		write(fd, &c, 1);
	}
}
