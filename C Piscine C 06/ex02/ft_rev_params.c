#include <unistd.h>

void	print(char *arr)
{
	int		cnt;
	char	*print;

	cnt = 0;
	print = arr;
	while (print[cnt])
	{
		write(1, &print[cnt], 1);
		cnt++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	cnt;

	cnt = argc - 1;
	while (cnt > 0)
	{
		print(argv[cnt--]);
	}
}
