/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:55:52 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 09:32:14 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	exception(int a, int b)
{
	if (a <= 0 || b <= 0 || a > 2147483647 || b > 2147483647)
	{
		return (0);
	}
	else
		return (1);
}

void	check_pos(int a, int b, int row, int col)
{
	while (row <= a)
	{
		if (row == 1 && col == 1)
			ft_putchar('A');
		else if (row == 1 && col == b)
			ft_putchar('C');
		else if (row == a && col == 1)
			ft_putchar('A');
		else if (row == a && col == b)
		{
			ft_putchar('C');
			break ;
		}
		else if (row == 1 || row == a || col == 1 || col == b)
			ft_putchar('B');
		else
			ft_putchar(' ');
		row++;
	}
}

void	rush(int a, int b)
{
	int	row;
	int	col;

	if (exception(a, b))
	{
		row = 1;
		col = 1;
		while (col <= b)
		{
			check_pos(a, b, row, col);
			col++;
			row = 1;
			ft_putchar('\n');
		}
	}
}