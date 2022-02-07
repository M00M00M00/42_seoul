int	matching(char *str, char *to_find, int len_of_f, char *ori_find)
{
	int	cnt;

	cnt = 0;
	while (cnt < len_of_f - 1)
	{
		if (*str == *to_find)
		{
			cnt++;
			str++;
			to_find++;
		}
		else
			break ;
	}
	if (cnt == len_of_f - 1)
		return (1);
	else
	{
		str = str - cnt;
		to_find = ori_find;
		cnt = 0;
	}
	return (0);
}

char	*str_find(char *str, char *to_find, int len_of_f, char *ori_find)
{
	char	*temp_str;

	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			temp_str = str;
			if (matching(str, to_find, len_of_f, ori_find))
				return (temp_str);
			str++;
		}
		else
			str++;
	}
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*original_find;
	int		cnt;

	cnt = 0;
	original_find = to_find;
	while (*to_find != '\0')
	{
		cnt++;
		to_find++;
	}
	to_find = original_find;
	return (str_find(str, to_find, cnt, original_find));
}
