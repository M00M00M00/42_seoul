int	ft_str_is_alpha(char *str)
{
	while (*str != '\n')
	{
		if (*str >= 'A' && *str <= 'z')
			return (1);
		str++;
	}
	return (0);
}