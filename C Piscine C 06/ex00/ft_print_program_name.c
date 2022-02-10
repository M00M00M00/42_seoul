#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		cnt;
	char	*print;

	cnt = 0;
	argc = 1;
	print = argv[0];
	while (print[cnt])
	{
		write(1, &print[cnt], 1);
		cnt++;
	}
	write(1, "\n", 1);
}
