/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:04:54 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 20:02:13 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "func.h"
#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	**make_int_map(char **map, int row_num, int col_num, t_map params)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	int_map = (int **) malloc(sizeof(int *) * row_num);
	while (i < row_num)
		int_map[i++] = (int *) malloc(sizeof(int) * col_num);
	i = 0;
	while (i < row_num)
	{
		j = 0;
		while (j < col_num)
		{
			if (map[i][j] == params.empty)
				int_map[i][j] = 1;
			else if (map[i][j] == params.obs)
				int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (int_map);
}

void	bsq(char *str, t_map params)
{
	t_pos	best_pos;
	char	**map;
	int		**map_int;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	params.col_num = i;
	map = ft_split(str, "\n", params.col_num, params.row_num);
	map_int = make_int_map(map, params.row_num, params.col_num, params);
	best_pos = find_best_pos(map_int, params.row_num, params.col_num);
	draw_ans(map, params, best_pos);
	i = 0;
	while (i < params.row_num + 1)
	{
		free(map[i]);
		if (i != params.row_num)
			free(map_int[i]);
		i++;
	}
	free(str);
	free(map);
	free(map_int);
}

int	main(int ac, char **av)
{
	t_map	params;
	char	*str;
	int		i;

	i = 1;
	if (ac == 1)
	{
		str = read_stdin(&params);
		if (!str || !check_str(str, params))
		{
			write(1, "map error\n", 10);
			return (0);
		}
		bsq(str, params);
		return (0);
	}
	while (i < ac)
	{
		str = read_file(&params, av[i++]);
		if (!str || !check_str(str, params))
			write(1, "map error\n", 10);
		else
			bsq(str, params);
	}
}
