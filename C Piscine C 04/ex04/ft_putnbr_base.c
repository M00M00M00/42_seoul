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
	base
}
void	ft_putnbr_base(int nbr, char *base)
{
	int arr[100];
	int	len_base;
	int	cnt;
	int	ans;

	cnt = 0;
	len_base = find_len(base);
	while (nbr > 0)
	{
		arr[cnt++] = nbr % len_base;
		nbr /= len_base;
	}
	cnt--;
	while (cnt > 0)
	{
		ans = arr[cnt--];
		write(1, &base[ans], 1);
	}
}

int main()
{
    ft_putnbr_base(1234123, "abcdefghij");

    return 0;
}
