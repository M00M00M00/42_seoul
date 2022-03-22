/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:16:00 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 15:16:00 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_Correct(int *arr, int idx, int i)
{
	int	cnt;

	cnt = 0;
	if (idx == 0)
		return (1);
	else
	{
		while (cnt < idx)
		{
			if (cnt - idx == (arr[cnt] - '0') - i \
			|| cnt - idx == i - (arr[cnt] - '0'))
				return (0);
			cnt++;
		}
	}
	return (1);
}

void	dfs(int idx, int n, int *arr, int *is_selected)
{
	int	i;

	i = 0;
	if (n == 10)
	{
		while (i < 10)
			write(1, &arr[i++], 1);
		arr[11] += 1;
		write(1, "\n", 1);
	}
	else
	{
		while (i < 10)
		{
			if (!is_selected[i] && is_Correct(arr, idx, i))
			{
				arr[idx] = i + '0';
				is_selected[i] = 1;
				dfs (idx + 1, n + 1, arr, is_selected);
				arr[idx] = -1;
				is_selected[i] = 0;
			}
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	arr[12];
	int	is_selected[12];

	i = 0;
	while (i < 12)
	{
		arr[i] = 0;
		is_selected[i] = 0;
		i++;
	}
	dfs(0, 0, arr, is_selected);
	return (arr[11]);
}
