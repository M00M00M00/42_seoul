#include <unistd.h>
int	find_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	check_base(char *base)
{
	int	cnt;
	int cnt_in;
	
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
		if (base[cnt] == '+' || base[cnt] == '-')
			return (0);
		cnt++;
	}
	return (1);
}

void	print_smallest(char *base)
{
	write(1, "-", 1);
	write(1, &base[2], 1);
	write(1, &base[1], 1);
	write(1, &base[4], 1);
	write(1, &base[7], 1);
	write(1, &base[4], 1);
	write(1, &base[8], 1);
	write(1, &base[3], 1);
	write(1, &base[6], 1);
	write(1, &base[4], 1);
	write(1, &base[8], 1);
}

void	print(int nbr, char *base, int arr[], int cnt)
{
	int len_base;
	int	ans;

	len_base = find_len(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr > 0)
	{
		arr[cnt++] = nbr % len_base;
		nbr /= len_base;
	}
	cnt--;
	while (cnt >= 0)
	{
		ans = arr[cnt--];
		write(1, &base[ans], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int arr[100];
	int	len_base;
	int	cnt;

	cnt = 0;
	len_base = find_len(base);
	if (len_base > 1 && check_base(base))
	{
		if (nbr == 0)
		{
			write(1, &base[0], 1);
			write(1, "\n", 1);
		}
		else if (nbr == -2147483648)
		{
			print_smallest(base);
			write(1, "\n", 1);
		}
		else
		{
			print(nbr, base, arr, cnt);
			write(1, "\n", 1);
		}
	}
}

int main()
{
    ft_putnbr_base(999, "abcdefghij");

    return 0;
}
