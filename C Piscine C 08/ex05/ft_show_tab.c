#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen1(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

void	ft_show_tab(struct s_stock_str *par)
{
	char	*str_print;
	char	size_print;
	char	*copy_print;
	int		i;

	i = 0;
	while (par[i].str)
	{
		str_print = par[i].str;
		size_print = par[i].size + '0';
		copy_print = par[i].copy;
		write(1, str_print, ft_strlen1(str_print));
		write(1, "\n", 1);
		write(1, &size_print, 1);
		write(1, "\n", 1);
		write(1, copy_print, ft_strlen1(copy_print));
		write(1, "\n", 1);
		i++;
	}
}
