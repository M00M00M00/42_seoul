#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		cnt;

	i = 0;
	j = 0;
	cnt = 0;
	if (size == 0)
		return ((void *) 0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{}
			cnt++;
			j++;
	}
}
