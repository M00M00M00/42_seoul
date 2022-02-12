int	find_len1(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	check_base1(char *base)
{
	int	cnt;
	int	cnt_in;

	cnt = 0;
	while (base[cnt])
	{
		cnt_in = 0;
		while (cnt_in < cnt)
		{
			if (base[cnt_in] == base[cnt])
				return (0);
			cnt_in++;
		}
		if (base[cnt] == '+' || base[cnt] == '-' || base[cnt] == '\t' \
		|| base[cnt] == '\n' || base[cnt] == '\v' || base[cnt] == '\f' \
		|| base[cnt] == '\r' || base[cnt] == ' ')
			return (0);
		cnt++;
	}
	return (1);
}

int	calculate1(char *str, char *base, int cnt_minus, int len_base)
{
	char			arr[100];
	int				cnt;
	long long		ans;

	cnt = 0;
	ans = 0;
	while (*base)
		arr[cnt++] = *base++;
	arr[cnt] = '\0';
	while (*str)
	{
		cnt = 0;
		while (cnt < len_base)
		{
			if (*str == arr[cnt])
				ans = ans * len_base + (long long) cnt;
			cnt++;
		}
		str++;
	}
	if (cnt_minus % 2 == 1)
		ans *= -1;
	return (ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int		cnt_minus;
	int		cnt;
	int		len_base;

	cnt_minus = 0;
	cnt = 0;
	len_base = find_len1(base);
	if (len_base > 1 && check_base1(base))
	{
		while ((*str == '\t' || *str == '\n' || *str == '\v'
				|| *str == '\f' || *str == '\r' || *str == ' '))
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str++ == '-')
				cnt_minus++;
		}
		return (calculate1(str, base, cnt_minus, len_base));
	}
	else
		return (0);
}
