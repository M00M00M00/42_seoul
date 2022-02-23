#include "map.h"
#include "func.h"
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	check_firstline(char *str);

char	*read_til(char *filename)
{
	char	*buff;
	int		fd;
	int		i;

	buff = malloc(sizeof(char) * 1024 * 1024 * 1024 + 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}
	i = read(fd, buff, 1024 * 1024 * 1024);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}
	buff[i] = 0;
	return (buff);
}

int	set_map_params(t_map *map, char *first_line)
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
	map->fill = first_line[i];
	if (map->row_num <= 0)
		return (0);
	free(line_num);
	return (1);
}

char	*read_file(t_map *map, char *filename)
{
	char	*str;
	char	*first_line;
	int		i;

	i = 0;
	str = read_til(filename);
	first_line = ft_strdup_til(str, '\n');
	if (!(set_map_params(map, first_line)))
		return (0);
	while (str[i] != 0)
		i++;
	if (str[i - 1] != '\n')
		ft_strncat(str, "\n", 1);
	while (*str != '\n' && *str != 0)
		str++;
	if (*str == '\n')
		str++;
	free(first_line);
	if (!(ft_strlen(str)))
		return (0);
	return (str);
}
