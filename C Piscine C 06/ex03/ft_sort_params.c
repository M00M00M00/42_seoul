/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:10:24 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 18:14:38 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

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

int	main(int argc, char **argv)
{
	int		cnt;
	int		cnt_in;
	char	*temp;

	cnt = argc - 1;
	while (cnt > 1)
	{
		cnt_in = 1;
		while (cnt_in < cnt)
		{
			if (ft_strcmp(argv[cnt_in], argv[cnt_in + 1]) > 0)
			{
				temp = argv[cnt_in];
				argv[cnt_in] = argv[cnt_in + 1];
				argv[cnt_in + 1] = temp;
			}
			cnt_in++;
		}
		cnt--;
	}
	cnt = 1;
	while (cnt < argc)
	{
		print(argv[cnt++]);
	}
}
