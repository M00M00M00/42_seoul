/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:40:11 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 17:43:40 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	calculate(long long arr[], long long n, long long cnt_minus)
{
	long long	ans;
	long long	cnt;

	cnt = 0;
	ans = 0;
	while (cnt < n)
		ans = 10 * ans + arr[cnt++];
	if (cnt_minus % 2 == 1)
		ans *= -1;
	return (ans);
}

long long	ft_atoi(const char *str)
{
	long long	cnt_minus;
	long long	arr[100];
	long long	cnt;

	cnt_minus = 0;
	cnt = 0;
	while ((*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			cnt_minus++;
	}
	while (*str >= '0' && *str <= '9')
		arr[cnt++] = (long long) *str++ - 48;
	return (calculate (arr, cnt, cnt_minus));
}
