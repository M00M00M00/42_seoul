/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:04:54 by mukim             #+#    #+#             */
/*   Updated: 2022/02/22 00:58:24 by moo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/func.h"
#include "../include/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file(t_map *map, char *filename);
char	**ft_split(char *str, char *charset, int col_num, int row_num);
t_pos	find_best_pos(int **map_int, int row_num, int col_num);
void	draw_ans(char **map, t_map params, t_pos best_pos);

char	**make_map(char **map, char *str, t_map *params)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] != '\n')
		i++;
	params->col_num = i;
	map = ft_split(str, "\n", params->col_num, params->row_num);
	return (map);
}

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

int	main(int ac, char **av)
{
	t_map	params;
	t_pos	best_pos;
	char	*str;
	char	**map;
	int		**map_int;

	if (ac == 2)
	{
		str = read_file(&params, av[1]);
		map = make_map(map, str, &params);
		map_int = make_int_map(map, params.row_num, params.col_num, params);
		best_pos = find_best_pos(map_int, params.row_num, params.col_num);
		draw_ans(map, params, best_pos);
	}
	return (0);
}
