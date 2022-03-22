/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:20:11 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 12:20:13 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate(int arr[], int n, int cnt_minus)
{
	int	ans;
	int	cnt;

	cnt = 0;
	ans = 0;
	while (cnt < n)
		ans = 10 * ans + arr[cnt++];
	if (cnt_minus % 2 == 1)
		ans *= -1;
	return (ans);
}

int	ft_atoi(char *str)
{
	int	cnt_minus;
	int	arr[100];
	int	cnt;

	cnt_minus = 0;
	cnt = 0;
	while ((*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			cnt_minus++;
	}
	while (*str >= '0' && *str <= '9')
		arr[cnt++] = (int) *str++ - 48;
	return (calculate (arr, cnt, cnt_minus));
}
