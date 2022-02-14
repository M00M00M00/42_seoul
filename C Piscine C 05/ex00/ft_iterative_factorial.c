int	ft_iterative_factorial(int nb)
{
	int ans;
	int	cnt;

	ans = 1;
	cnt = 1;
	while (cnt < nb + 1)
	{
		ans *= cnt;
		cnt++;
	}

	return (ans);
}
