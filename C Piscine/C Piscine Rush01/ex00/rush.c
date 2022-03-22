/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:29:47 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 21:07:29 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		count(int **table, int xy, int try_i, int size);
void	dfs(int **table, int xy, int size, int **bits);

void	print_table(int **table, int size)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			c = table[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

int	isCorrect(int x, int y, int try_i, int **bits)
{
	if (bits[0][x] & (1 << try_i))
		return (0);
	if (bits[1][y] & (1 << try_i))
		return (0);
	return (1);
}

void	set_number(int **table, int xyi, int size, int **bits)
{
	int	x;
	int	y;
	int	i;

	x = xyi / 100;
	y = (xyi / 10) % 10;
	i = xyi % 10;
	table[x][y] = i;
	bits[0][x] |= (1 << i);
	bits[1][y] |= (1 << i);
	if (y == size)
		dfs(table, (x + 1) * 10 + 1, size, bits);
	else
		dfs(table, x * 10 + y + 1, size, bits);
	table[x][y] = 0;
	bits[0][x] &= ~(1 << i);
	bits[1][y] &= ~(1 << i);
}

void	dfs(int **table, int xy, int size, int **bits)
{
	int	i;
	int	x;
	int	y;

	x = xy / 10;
	y = xy % 10;
	if (x == size + 1 && y == 1)
	{
		print_table(table, size);
		table[size + 1][size + 1] = 1;
		return ;
	}
	i = 1;
	while (i <= size)
	{
		if (isCorrect(x, y, i, bits) && count(table, xy, i, size))
			set_number(table, xy * 10 + i, size, bits);
		i++;
	}
}
