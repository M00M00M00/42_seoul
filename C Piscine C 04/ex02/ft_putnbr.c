#include <unistd.h>
void	print(int nb)
{
	int	arr[100];
	int	cnt;

	cnt = 0;
	while (nb > 0)
	{
		arr[cnt] = nb % 10 + '0';
		cnt++;
		nb /= 10;
	}
	while (cnt > 0)
	{
		write(1, &arr[cnt - 1], 1);
		cnt--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		print(nb);
	}
}
