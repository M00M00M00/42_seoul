/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:09:18 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 20:48:13 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char1(char a, char b)
{	
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
}

void	print_char2(char c, char d)
{	
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, ", ", 2);
}

void	last_print(void)
{
	write(1, "98 99", 5);
}

void	ft_print_comb2(void)
{
	int	t1;
	int	t2;

	t1 = 0;
	while (t1 < 98)
	{
		t2 = t1 + 1;
		while (t2 < 100)
		{
			print_char1(t1 / 10 + '0', t1 % 10 + '0');
			print_char2(t2 / 10 + '0', t2 % 10 + '0');
			t2++;
		}
		t1 ++;
	}
	last_print();
}
