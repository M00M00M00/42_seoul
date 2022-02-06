/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:55:52 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 09:31:37 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	exception(int x, int y)
{
	if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647)
	{
		return (0);
	}
	else
		return (1);
}

void	check_pos(int x, int y, int row, int col)
{
	while (row <= x)
	{
		if ((row == 1 && col == 1) || (row == 1 && col == y))
			ft_putchar('o');
		else if ((row == x && col == 1) || (row == x && col == y))
		{
			ft_putchar('o');
			break ;
		}
		else if (row == 1 || row == x)
			ft_putchar('|');
		else if (col == 1 || col == y)
			ft_putchar('-');
		else
			ft_putchar(' ');
		row++;
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (exception(x, y))
	{
		row = 1;
		col = 1;
		while (col <= y)
		{
			check_pos(x, y, row, col);
			col++;
			row = 1;
			ft_putchar('\n');
		}
	}
}
