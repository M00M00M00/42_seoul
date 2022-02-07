void	capitalize(char *str, int sw_for_space)
{
	while (*str != '\0')
	{
		if (sw_for_space == 1)
		{
			if (*str >= 'a' && *str <= 'z')
			{
				*str = *str - 32;
				str++;
			}
			else
				str++;
		}
		else
			str++;
		if (*str == ' ')
		{
			sw_for_space = 1;
			*str = ' ';
			str++;
			if (*str == '\0')
				break ;
		}
		else
			sw_for_space = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*original_str;
	int		sw_for_space;

	original_str = str;
	sw_for_space = 1;
	capitalize(str, sw_for_space);
	return (original_str);
}
