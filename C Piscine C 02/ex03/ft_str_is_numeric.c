int	ft_str_is_numeric(char *str)
{
	int	sw;

	sw = 1;
	if (*str == '\0')
		return (1);
	else
	{
		while (*str != '\0')
		{
			if (*str >= '0' && *str <= '9')
				sw *= 1;
			else
				sw *= 0;
			str++;
		}
		if (sw == 1)
			return (1);
		else
			return (0);
	}
}