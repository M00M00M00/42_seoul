/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:24 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 18:32:58 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	find_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	check_base(char *base)
{
	int	cnt;
	int	cnt_in;

	cnt = 0;
	while (base[cnt])
	{
		cnt_in = 0;
		while (cnt_in < cnt)
		{
			if (base[cnt_in] == base[cnt])
				return (0);
			cnt_in++;
		}
		if (base[cnt] == '+' || base[cnt] == '-')
			return (0);
		cnt++;
	}
	return (1);
}

void	print1(long long nbr, char *base, int arr[], int cnt)
{
	long long	len_base;
	long long	ans;

	len_base = find_len(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr > 0)
	{
		arr[cnt++] = nbr % len_base;
		nbr /= len_base;
	}
	cnt--;
	while (cnt >= 0)
	{
		ans = arr[cnt--];
		write(1, &base[ans], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	arr[100];
	int	len_base;
	int	cnt;

	cnt = 0;
	len_base = find_len(base);
	if (len_base > 1 && check_base(base))
	{
		if (nbr == 0)
			write(1, &base[0], 1);
		else
			print1(nbr, base, arr, cnt);
	}
}
