/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:50 by sangjupa          #+#    #+#             */
/*   Updated: 2022/02/20 19:16:12 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "s_dict.h"

char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
int		ft_str_is_numeric(char *str);
int		ft_str_is_alpha(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	put_str(char *str);
void	ft_input_atoi(char **argv);
int		dict_check(char *buff, int i, int count);
void	put_digit(char now, int jari, t_dict *arr);
void	put0(char now, t_dict *arr);
void	put1(char prev, char now, t_dict *arr);
void	put2(char now, char next, t_dict *arr);
t_dict	*make_dict(int i, int count);

int	dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

void	rush02(char **argv, t_dict *arr, int len)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((len - i) % 3 == 0)
			put0(argv[1][i], arr);
		else if ((len - i) % 3 == 1)
		{
			if (i != 0)
			{
				put1(argv[1][i - 1], argv[1][i], arr);
				put_digit(argv[1][i], len - i, arr);
			}
			else
			{
				put1(0, argv[1][i], arr);
				put_digit(argv[1][i], len - i, arr);
			}
		}
		else if ((len - i) % 3 == 2)
			put2(argv[1][i], argv[1][i + 1], arr);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dict	*arr;
	int		len;

	arr = make_dict(0, 0);
	if (arr == 0)
		return (0);
	if (argc == 2)
	{
		ft_input_atoi(&argv[0]);
		len = ft_strlen(argv[1]);
		rush02(argv, arr, len);
	}
	write(1, "\n", 1);
}
