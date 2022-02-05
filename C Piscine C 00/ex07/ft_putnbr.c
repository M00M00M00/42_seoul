#include <unistd.h>
void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_int_putchar(char a)
{
	a += 48;
	write(1, &a, 1);
}

void	print_small(void)
{
	ft_putchar('-');
	ft_int_putchar(2);
	ft_int_putchar(1);
	ft_int_putchar(4);
	ft_int_putchar(7);
	ft_int_putchar(4);
	ft_int_putchar(8);
	ft_int_putchar(3);
	ft_int_putchar(6);
	ft_int_putchar(4);
	ft_int_putchar(8);
}

void	print_pos(int nb, int cnt, int arr[])
{
	int	a;

	while (nb > 0)
	{
		a = nb % 10;
		arr[cnt] = a;
		cnt++;
		nb = nb / 10;
	}
	cnt--;
	while (cnt >= 0)
	{
		ft_int_putchar(arr[cnt]);
		cnt--;
	}
}

void	ft_putnbr(int nb)
{
	int	a;
	int	arr[12];
	int	cnt;

	if (nb == -2147483648)
	{
		print_small();
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -1 * nb;
		}
		cnt = 0;
		if (nb == 0)
		{
			ft_int_putchar(0);
		}
		else
			print_pos(nb, cnt, arr);
	}
}
