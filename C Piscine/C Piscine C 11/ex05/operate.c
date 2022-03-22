/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:32:40 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 13:52:58 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putnbr(int nb);

void	plus(int a1, int a2)
{
	int	i;

	i = a1 + a2;
	ft_putnbr(i);
}

void	minus(int a1, int a2)
{
	int	i;

	i = a1 - a2;
	ft_putnbr(i);
}

void	multi(int a1, int a2)
{
	int	i;

	i = a1 * a2;
	ft_putnbr(i);
}

void	div(int a1, int a2)
{
	int	i;

	if (a2 == 0)
		write(1, "Stop : division by zero", 23);
	else
	{
		i = a1 / a2;
		ft_putnbr(i);
	}
}

void	mod(int a1, int a2)
{
	int	i;

	if (a2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		i = a1 % a2;
		ft_putnbr(i);
	}
}
