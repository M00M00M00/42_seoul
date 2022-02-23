#include "map.h"
#include "func.h"
#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	draw_ans(char **map, t_map params, t_pos best_pos)
{
	int	i;
	int	j;
	int	max;

	max = best_pos.content;
	i = 0;
	while (i < params.row_num)
	{
		j = 0;
		while (j < params.col_num)
		{
			if (i > best_pos.x - max && i <= best_pos.x \
				&& j > best_pos.y - max && j <= best_pos.y)
				write(1, &params.fill, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
