/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:20:57 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 13:52:45 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		ft_atoi(char *str);
void	plus(int a1, int a2);
void	minus(int a1, int a2);
void	multi(int a1, int a2);
void	div(int a1, int a2);
void	mod(int a1, int a2);

void	operate(int a1, char oper, int a2)
{
	if (oper == '+')
		plus(a1, a2);
	else if (oper == '-')
		minus(a1, a2);
	else if (oper == '*')
		multi(a1, a2);
	else if (oper == '/')
		div(a1, a2);
	else if (oper == '%')
		mod(a1, a2);
}

int	main(int ac, char **av)
{
	int		a1;
	int		a2;
	char	*oper;

	if (ac != 4)
		return (0);
	a1 = ft_atoi(av[1]);
	oper = av[2];
	a2 = ft_atoi(av[3]);
	if (*(oper + 1) != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (*oper != '+' && *oper != '-' && \
		*oper != '/' && *oper != '*' && *oper != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	operate(a1, *oper, a2);
	write(1, "\n", 1);
	return (0);
}
