/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:09:18 by mukim             #+#    #+#             */
/*   Updated: 2022/02/03 21:09:37 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_int_putchar(char a)
{
	a += 48;
	write(1, &a, 1);
}

void	print_char(char a, char b, char c, char d)
{	
	ft_int_putchar(a);
	ft_int_putchar(b);
	ft_putchar(' ');
	ft_int_putchar(c);
	ft_int_putchar(d);
	ft_putchar(',');
	ft_putchar(' ');
}

void	last_print(void)
{
	char	a;
	char	b;

	a = 9;
	b = 8;
	ft_int_putchar(a);
	ft_int_putchar(b);
	ft_putchar(' ');
	ft_int_putchar(a);
	ft_int_putchar(a);
}

void	ft_print_comb2(void)
{
	int	temp1;
	int	temp2;

	temp1 = 0;
	while (temp1 < 98)
	{
		temp2 = temp1 + 1;
		while (temp2 < 100)
		{
			print_char(temp1 / 10, temp1 % 10, temp2 / 10, temp2 % 10);
			temp2 ++;
		}
		temp1 ++;
	}
	last_print();
}
