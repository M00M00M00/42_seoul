#include "map.h"
#include "func.h"
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	check_firstline(char *str);

char	*read1_file(char sep, int i)
{
	char	*buff;
	char	*temp;
	char	*return_char;

	buff = malloc(sizeof(char));
	if (!(buff))
		return (0);
	return_char = malloc(sizeof(char));
	if (!(return_char))
		return (0);
	*return_char = '\0';
	while (read(0, buff, 1) > 0 && *buff != sep)
	{
		temp = return_char;
		return_char = malloc(sizeof(char) * (i++ + 1));
		if (!(return_char))
			return (0);
		return_char[0] = '\0';
		ft_strcat(return_char, temp);
		ft_strncat(return_char, buff, 1);
		free(temp);
	}
	free(buff);
	return_char[i] = 0;
	return (return_char);
}

int	set_map_params1(t_map *map, char *first_line)
{
	char	*line_num;
	int		i;
	int		line_len;

	i = 0;
	line_len = ft_strlen(first_line);
	line_num = malloc(sizeof(char) * (line_len - 2));
	if (!(line_num))
		return (0);
	if (!(check_firstline(first_line)))
		return (0);
	while (first_line[i + 3] != '\0')
	{
		line_num[i] = first_line[i];
		i++;
	}
	line_num[i] = '\0';
	map->row_num = ft_atoi(line_num);
	map->empty = first_line[i++];
	map->obs = first_line[i++];
	map->fill = first_line[i++];
	if (map->row_num <= 0)
		return (0);
	free(line_num);
	return (1);
}

char	*read_stdin(t_map *map)
{
	char	*str;
	char	*first_line;
	char	*temp;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 1024 * 1024 * 1024);
	*str = 0;
	first_line = read1_file('\n', 0);
	if (!(set_map_params1(map, first_line)))
		return (0);
	while (i < map->row_num)
	{
		temp = read1_file('\n', 0);
		ft_strcat(str, temp);
		ft_strncat(str, "\n", 1);
		free(temp);
		i++;
	}
	free(first_line);
	if (!(ft_strlen(str)))
		return (0);
	return (str);
}
