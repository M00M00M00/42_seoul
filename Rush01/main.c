#include <stdlib.h>
#include <unistd.h>

void	dfs(int **table, int xy, int size, int **bits);

int	check_argv(char *argv, int i, int num, int is_num)
{
	while (argv[i] != '\0')
	{
		if (!(argv[i] == ' ' || ('1' <= argv[i] && argv[i] <= '9')))
			return (0);
		i++;
	}
	i = 0;
	while (argv[i] != '\0')
	{
		if (('1' <= argv[i] && argv[i] <= '9') && is_num)
		{
			num++;
			is_num = 0;
		}
		else if (argv[i] == ' ' && !is_num)
			is_num = 1;
		else
			return (0);
		i++;
	}
	if (is_num)
		return (0);
	if (num == 0 || num % 4 != 0)
		return (0);
	return (num / 4);
}

void	putin_table(int **table, char *argv, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size + 1)
	{
		table[0][i] = argv[j] - '0';
		table[size + 1][i] = argv[j + size * 2] - '0';
		table[i][0] = argv[j + size * 2 * 2] - '0';
		table[i][size + 1] = argv[j + size * 2 * 3] - '0';
		i++;
		j += 2;
	}
}

int	**make_table(int size)
{
	int	i;
	int	j;
	int	**table;

	table = (int **)malloc(sizeof(int *) * (size + 2));
	i = 0;
	while (i < size + 2)
	{
		table[i] = (int *)malloc(sizeof(int) * (size + 2));
		i++;
	}
	i = 0;
	j = 0;
	while (i < size + 2)
	{
		while (j < size + 2)
		{
			table[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**make_bits(int size)
{
	int	i;
	int	**bits;

	bits = (int **)malloc(sizeof(int *) * 2);
	bits[0] = (int *)malloc(sizeof(int) * (size + 1));
	bits[1] = (int *)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size + 1)
	{
		bits[0][i] = 0;
		bits[1][i] = 0;
		i++;
	}
	return (bits);
}

int	main(int argc, char **argv)
{
	int	size;
	int	**table;
	int	**bits;

	size = check_argv(argv[1], 0, 0, 1);
	table = make_table(size);
	if (argc != 2 || !check_argv(argv[1], 0, 0, 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	putin_table(table, argv[1], size);
	bits = make_bits(size);
	dfs(table, 11, size, bits);
	if (table[size + 1][size + 1] != 1)
		write(1, "Error1\n", 6);
	return (0);
}
