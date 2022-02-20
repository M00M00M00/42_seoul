#include "map.h"
#include "func.h"
#include "main.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	t_map params;
	int		fd;
	char	*str;

	fd = open("../grid1.txt", O_RDONLY);
	str = read_file(fd, &params);
	printf
}
