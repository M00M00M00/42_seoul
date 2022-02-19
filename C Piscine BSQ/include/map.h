#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		row_num;
	int		col_num;
	char	empty;
	char	obs;
	char	fill;
}t_map;

typedef struct s_pos
{
	int	x;
	int	y;
	int	content;
}t_pos;

#endif
 