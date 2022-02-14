/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:29:27 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 21:04:56 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_cnt_left(int **table, int temp, int x, int y);
int	get_cnt_up(int **table, int temp, int x, int y);

int	countLeft(int **table, int x, int y, int size)
{
	int	temp;
	int	cnt;

	temp = 0;
	cnt = get_cnt_left(table, temp, x, y);
	if (cnt > table[x][0])
	{
		table[x][y] = 0;
		return (0);
	}
	if (temp == size)
	{
		if (cnt != table[x][0])
		{
			table[x][y] = 0;
			return (0);
		}
	}
	return (1);
}

int	countRight(int **table, int x, int y, int size)
{
	int	temp;
	int	cnt;
	int	i;

	temp = 0;
	cnt = 0;
	i = size;
	while (i > 0)
	{
		if (temp < table[x][i])
		{
			cnt++;
			temp = table[x][i];
		}
		i--;
	}
	if (cnt != table[x][size + 1])
	{
		table[x][y] = 0;
		return (0);
	}
	return (1);
}

int	countUp(int **table, int x, int y, int size)
{
	int	temp;
	int	cnt;

	temp = 0;
	cnt = get_cnt_up(table, temp, x, y);
	if (cnt > table[0][y])
	{
		table[x][y] = 0;
		return (0);
	}
	if (temp == size)
	{
		if (cnt != table[0][y])
		{
			table[x][y] = 0;
			return (0);
		}
	}
	return (1);
}

int	countDown(int **table, int x, int y, int size)
{
	int	temp;
	int	cnt;
	int	i;

	temp = 0;
	cnt = 0;
	i = size;
	while (i > 0)
	{
		if (temp < table[i][y])
		{
			cnt++;
			temp = table[i][y];
		}
		i--;
	}
	if (cnt != table[size + 1][y])
	{
		table[x][y] = 0;
		return (0);
	}
	return (1);
}

int	count(int **table, int xy, int try_i, int size)
{
	int	x;
	int	y;

	x = xy / 10;
	y = xy % 10;
	table[x][y] = try_i;
	if (!countLeft(table, x, y, size))
		return (0);
	if (y == size)
		if (!countRight(table, x, y, size))
			return (0);
	if (!countUp(table, x, y, size))
		return (0);
	if (x == size)
		if (!countDown(table, x, y, size))
			return (0);
	table[x][y] = 0;
	return (1);
}
