int	is_word(char *str)
{
	int		sw;

	sw = 1;
	while (*str != '\0' && *str != ' ')
	{
		if (*str >= 'a' && *str <= 'z')
			sw *= 1;
		else if (*str >= 'A' && *str <= 'Z')
			sw *= 1;
		else if (*str >= '0' && *str <= '9')
			sw *= 1;
		else
			return(0);
		str++;
	}
	return (1);
}

void	change_word(char *str)
{
	if	(*str >= 'a' && *str <= 'z')
		*str -= 32;
	str++;
	while (*str != '\0' && *str != ' ')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	char *original_str;
	int	sw_space;

	original_str = str;
	sw_space = 1;
	while (*str != '\0')
	{
		if (sw_space)
		{
			if (is_word(str))
				change_word(str);
			sw_space = 0;
		}
		if (*str == ' ')
			sw_space = 1;
		str++;
	}
	str = original_str;
	return (str);
}
