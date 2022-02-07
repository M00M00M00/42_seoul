int	ft_str_is_uppercase(char *str)
{
	int	sw;

	sw = 1;
	if (*str == '\0')
		return (1);
	else
	{
		while (*str != '\0')
		{
			if (*str >= 'A' && *str <= 'Z')
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