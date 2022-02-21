#include "../include/map.h"
#include "../include/func.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*read_til(int fd, char sep, int i)
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
	while (read(fd, buff, 1) > 0 && *buff != sep)
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
	return_char[i] = '\0';
	return (return_char);
}

void	set_map_params(t_map *map, char *first_line)
{
	char	*line_num;
	int		i;
	int		line_len;

	i = 0;
	line_len = ft_strlen(first_line);
	line_num = malloc(sizeof(char) * (line_len - 2));
	// if (!(line_num))
	// 	return (0);
	while (first_line[i + 3] != '\0')
	{
		line_num[i] = first_line[i];
		i++;
	}
	line_num[i] = '\0';
	map->row_num = ft_atoi(line_num);
	map->empty = first_line[i++];
	map->obs = first_line[i++];
	map->fill = first_line[i];
	free(line_num);
	printf("row_num : %d\n", map->row_num);
	printf("empty : %s\n", &map->empty);
	printf("obs : %s\n", &map->obs);
	printf("fill : %s\n", &map->fill);
	// return (1);
}

char	*read_file(int fd, t_map *map)
{
	char	*str;
	char	*first_line;

	first_line = read_til(fd, '\n', 1);
	printf("%s\n", first_line);

	// set_map_params(map, first_line);
	// if (!(set_map_params(map, read_til(fd, '\n', 1))))
	// 	return (0);
	
	str = read_til(fd, '\0', 1);
	printf("%s\n", str);
	if (!(ft_strlen(str)))
		return (0);
	
	return (str);
}
