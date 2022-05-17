/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:29:54 by mukim             #+#    #+#             */
/*   Updated: 2022/05/17 16:11:49 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putuint_fd(int i, int fd)
{
	char			c;
	unsigned int	n;

	n = (unsigned int) i;
	c = '0';
	if (n >= 10)
	{
		ft_putuint_fd(n / 10, fd);
		c += n % 10;
		write(fd, &c, 1);
	}
	else
	{
		c += n % 10;
		write(fd, &c, 1);
	}
}
