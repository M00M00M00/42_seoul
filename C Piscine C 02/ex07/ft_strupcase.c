char	*ft_strupcase(char *str)
{
	char    *original_str;

	original_str = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (original_str);
}