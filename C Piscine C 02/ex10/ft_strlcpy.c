unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	char	*origin_dest;
	unsigned int	cnt;

	cnt = 0;
	origin_dest = dest;
	while (cnt < n - 1 || *stc != '\0')
	{
		*dest = *src;
		cnt++;
		dest++;
		src++;
	}
	if (cnt == n - 1)
		cnt++;
	*dest = '\0';
	dest = origin_dest;
	return (cnt);
}
