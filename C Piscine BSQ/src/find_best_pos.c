#include "map.h"
#include "func.h"
#include "main.h"
#include <stdio.h>

int	find_min(int a, int b, int c)
{
	int	temp;

	if (a < b)
		temp = a;
	else
		temp = b;
	if (temp < c)
		return (temp);
	return (c);
}

int	find_max(int **map_int, int row_num, int col_num)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < row_num)
	{
		j = 0;
		while (j < col_num)
		{
			if (temp <= map_int[i][j])
				temp = map_int[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

t_pos	find_pos(int **map_int, int row_num, int col_num, int max)
{
	t_pos	best_pos;
	int		i;
	int		j;

	i = 0;
	while (i < row_num)
	{
		j = 0;
		while (j < col_num)
		{
			if (map_int[i][j] == max)
			{
				best_pos.x = i;
				best_pos.y = j;
				best_pos.content = max;
				i = row_num - 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (best_pos);
}

t_pos	find_best_pos(int **map_int, int row_num, int col_num)
{
	int		i;
	int		j;
	int		max;

	i = 1;
	while (i < row_num)
	{
		j = 1;
		while (j < col_num)
		{
			if (map_int[i][j])
				map_int[i][j] = find_min(map_int[i - 1][j - 1], \
				map_int[i - 1][j], map_int[i][j - 1]) + 1;
			j++;
		}
		i++;
	}
	max = find_max(map_int, row_num, col_num);
	return (find_pos(map_int, row_num, col_num, max));
}
