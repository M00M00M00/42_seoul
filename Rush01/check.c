int countLeft(int **table, int x, int y, int size)
{
	int temp;
	int cnt;
	int i;

	temp = 0;
	cnt = 0;
	i = 1;
	while (i <= y)
	{
		if (temp < table[x][i])
		{
			cnt++;
			temp = table[x][i];
		}
		i++;
	}
	if (cnt > table[x][0])
	{
		table[x][y] = 0;
		return (0);
	}
	if (temp == size)
	{
		if (cnt != table[x][0])
		{
			table[x][y] = 0;
			return (0);
		}
	}
	return (1);
}

int countRight(int **table, int x, int y, int size)
{
	int temp;
	int cnt;
	int i;

	temp = 0;
	cnt = 0;
	i = size;
	while (i > 0)
	{
		if (temp < table[x][i])
		{
			cnt++;
			temp = table[x][i];
		}
		i--;
	}
	if (cnt != table[x][size + 1])
	{
		table[x][y] = 0;
		return (0);
	}
	return (1);
}

int countUp(int **table, int x, int y, int size)
{
	int temp;
	int cnt;
	int i;

	temp = 0;
	cnt = 0;
	i = 1;
	while (i <= x)
	{
		if (temp < table[i][y])
		{
			cnt++;
			temp = table[i][y];
		}
		i++;
	}
	if (cnt > table[0][y])
	{
		table[x][y] = 0;
		return (0);
	}
	if (temp == size)
	{
		if (cnt != table[0][y])
		{
			table[x][y] = 0;
			return (0);
		}
	}
	return (1);
}

int countDown(int **table, int x, int y, int size)
{
	int temp;
	int cnt;
	int i;

	temp = 0;
	cnt = 0;
	i = size;
	while (i > 0)
	{
		if (temp < table[i][y])
		{
			cnt++;
			temp = table[i][y];
		}
		i--;
	}
	if (cnt != table[size + 1][y])
	{
		table[x][y] = 0;
		return (0);
	}
	return (1);
}

int count(int **table, int xy, int try_i, int size)
{
	int x = xy / 10;
	int y = xy % 10;
	table[x][y] = try_i;

	if (!countLeft(table, x, y, size))
		return (0);
	if (y == size)
		if (!countRight(table, x, y, size))
			return (0);
	if (!countUp(table, x, y, size))
		return (0);
	if (x == size)
		if (!countDown(table, x, y, size))
			return (0);

	table[x][y] = 0;
	return (1);
}
