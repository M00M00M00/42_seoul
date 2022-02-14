#include <unistd.h>

int count(int **table, int xy, int try_i, int size);

void print_table(int **table, int size)
{
	int i;
	int j;
	char c;

	i = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			c = table[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return;
}

int isCorrect(int x, int y, int try_i, int **bits)
{
	if (bits[0][x] & (1 << try_i))
		return (0);
	if (bits[1][y] & (1 << try_i))
		return (0);
	return (1);
}

void dfs(int **table, int xy, int size, int **bits)
{
	int i;
	int x = xy / 10;
	int y = xy % 10;
	int s;

	s = 0;
	if (x == size + 1 && y == 1)
	{
		print_table(table, size);
		table[size+1][size+1] = 1;
		return ;
	}

	i = 1;
	while (i <= size)
	{
		if (isCorrect(x, y, i, bits) && count(table, xy, i, size))
		{
			table[x][y] = i;
			bits[0][x] |= (1 << i);
			bits[1][y] |= (1 << i);

			if (y == size)
				dfs(table, (x + 1) * 10 + 1, size, bits);
			else
				dfs(table, x * 10 + y + 1, size, bits);

			table[x][y] = 0;
			bits[0][x] &= ~(1 << i);
			bits[1][y] &= ~(1 << i);
		}
		i++;
	}
}
