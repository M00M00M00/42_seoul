int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	else
	{
		while (*str != '\0')
		{
			if (*str < 32 || *str > 126)
				return(0);
			str++;
		}
	}
	return (1);
}
