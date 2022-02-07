char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*original_dest;
	unsigned int	cnt;

	cnt = 0;
	original_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && cnt < nb)
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	return (original_dest);
}
