/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:22 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 21:11:24 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *arr)
{
	int		cnt;
	char	*print;

	cnt = 0;
	print = arr;
	while (print[cnt])
	{
		write(1, &print[cnt], 1);
		cnt++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	cnt;

	cnt = 1;
	while (cnt < argc)
	{
		print(argv[cnt++]);
	}
}
