char	*ft_strlowcase(char *str)
{
	char    *original_str;

	original_str = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (original_str);
}