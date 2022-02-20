/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:43:55 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 14:34:29 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen1(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
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

void	ft_show_tab(struct s_stock_str *par)
{
	char	*str_print;
	char	size_print;
	char	*copy_print;
	int		i;

	i = 0;
	while (par[i].str)
	{
		str_print = par[i].str;
		size_print = par[i].size;
		copy_print = par[i].copy;
		write(1, str_print, ft_strlen1(str_print));
		write(1, "\n", 1);
		ft_putnbr(size_print);
		write(1, "\n", 1);
		write(1, copy_print, ft_strlen1(copy_print));
		write(1, "\n", 1);
		i++;
	}
}
