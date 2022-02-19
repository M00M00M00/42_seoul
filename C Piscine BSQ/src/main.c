#include <map.h>
#include <func.h>
#include <main.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	t_map params;
	char	*str;
	int		fd;

	fd = open("../grid.txt", O_RDONLY);
	printf("%s\n", read_file(fd, &params));
}
