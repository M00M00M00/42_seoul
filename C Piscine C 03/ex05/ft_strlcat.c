unsigned int	find_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*original_dest;
	unsigned int	cnt;
	unsigned int	ans;
	unsigned int	len_dest;

	cnt = 0;
	len_dest = find_len(dest);
	ans = len_dest + find_len(src);
	original_dest = dest;
	if (len_dest >= size)
		return (ans);
	dest += find_len(dest);
	while (*src != '\0' && cnt < (size - len_dest - 1))
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	return (ans);
}
