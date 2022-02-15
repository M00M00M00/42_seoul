#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	cnt;
	int	*arr;

	cnt = 0;
	if (min >= max)
	{
		*range = (void *) 0;
		return (0);
	}
	arr = (int *) malloc(sizeof(int) * (max - min));
	if (arr == 0)
		return (-1);
	while (min < max)
	{
		arr[cnt] = min;
		cnt++;
		min++;
	}
	*range = arr;
	return (cnt);
}
