#include <unistd.h>

void	get_hexstring(unsigned char temp)
{
	int	cnt;
	char	hex[2];

	cnt = 0;
	hex[0] = temp / 16;
	hex[1] = temp % 16;
	while (cnt < 2)
	{
		if (hex[cnt] < 10)
			hex[cnt] += 48;
		else
			hex[cnt] += 87;
		cnt++;
	}
	write(1, &hex[0], 1);
	write(1, &hex[1], 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*original_str;
	unsigned char	temp;

	original_str = str;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			temp = *str;
			write(1, "\\", 1);
			get_hexstring(temp);
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	str = original_str;
}
