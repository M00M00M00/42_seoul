/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:00 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 21:11:02 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		cnt;
	char	*print;

	cnt = 0;
	argc = 1;
	print = argv[0];
	while (print[cnt])
	{
		write(1, &print[cnt], 1);
		cnt++;
	}
	write(1, "\n", 1);
}
