/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:41:13 by mukim             #+#    #+#             */
/*   Updated: 2022/05/17 16:14:00 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putupperhex_fd(int i, int fd)
{
	int				cnt;
	int				idx;
	char			hexp[100];
	unsigned int	n;

	cnt = 0;
	n = (unsigned int) i;
	while (n > 0)
	{
		hexp[cnt++] = n % 16;
		n /= 16;
	}
	idx = 0;
	while (idx < cnt)
	{
		if (hexp[idx] < 10)
			hexp[idx] = hexp[idx] + 48;
		else
			hexp[idx] = hexp[idx] + 55;
		idx++;
	}
	while (idx > 0)
		write(fd, &hexp[idx-- - 1], 1);
}
