#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	cnt;
	int	*range;

	i = min;
	cnt = 0;
	if (min >= max)
		return (0);
	range = (int *) malloc(sizeof(int) * (max - min));
	while (i < max)
		range[cnt++] = i++;
	return (range);
}
