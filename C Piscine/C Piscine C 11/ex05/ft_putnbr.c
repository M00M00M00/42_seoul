/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:37:33 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 12:37:34 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_small(void)
{
	write(1, "-2147483648", 11);
}

void	print_pos(int nb, int cnt, int arr[])
{
	int	a;
	int	temp;

	while (nb > 0)
	{
		a = nb % 10;
		arr[cnt] = a;
		cnt++;
		nb = nb / 10;
	}
	cnt--;
	while (cnt >= 0)
	{
		temp = arr[cnt] + '0';
		write(1, &temp, 1);
		cnt--;
	}
}

void	ft_putnbr(int nb)
{
	int	arr[12];
	int	cnt;
	int	zero;

	zero = 0 + '0';
	if (nb == -2147483648)
	{
		print_small();
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -1 * nb;
		}
		cnt = 0;
		if (nb == 0)
		{
			write(1, &zero, 1);
		}
		else
			print_pos(nb, cnt, arr);
	}
}
