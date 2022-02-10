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
	int		cnt;
	int		cnt_in;
	char	temp;

	cnt = argc - 1;
	while (cnt > 1)
	{
		cnt_in = 1;
		while (cnt_in < cnt)
		{
			if (*argv[cnt_in] > *argv[cnt_in + 1])
			{
				temp = *argv[cnt_in];
				*argv[cnt_in] = *argv[cnt_in + 1];
				*argv[cnt_in + 1] = temp;
			}
			cnt_in++;
		}
		cnt--;
	}
	cnt = 1;
	while (cnt < argc)
	{
		print(argv[cnt++]);
	}
}
