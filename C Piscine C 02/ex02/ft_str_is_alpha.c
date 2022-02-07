int	ft_str_is_alpha(char *str)
{
	int	sw;

	sw = 1;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'z')
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