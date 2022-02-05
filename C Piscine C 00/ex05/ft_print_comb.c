/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:04:59 by mukim             #+#    #+#             */
/*   Updated: 2022/02/03 20:10:24 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	three_putchar(char	a, char b, char c)
{
	a += 48;
	b += 48;
	c += 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	print(int a, int b, int c)
{
	three_putchar(a, b, c);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	arr[3];

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	while (1)
	{
		arr[2] = arr[2] + 1;
		if (arr[2] == 10)
		{
			arr[1] = arr[1] + 1;
			if (arr[1] == 9)
			{
				arr[0] = arr[0] + 1;
				arr[1] = arr[0] + 1;
			}
			arr[2] = arr[1] + 1;
		}
		if (arr[0] == 7 && arr[1] == 8 && arr[2] == 9)
		{
			three_putchar(7, 8, 9);
			break ;
		}
		print(arr[0], arr[1], arr[2]);
	}
}
