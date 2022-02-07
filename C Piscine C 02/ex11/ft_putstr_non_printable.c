#include <unistd.h>

void	get_hexstring(char *str, char *hex)
{
	int	cnt;
	char *original_hex;

	cnt = 0;
	original_hex = hex;
	*hex = *str / 16;
	hex++;
	*hex = *str % 16;
	hex = original_hex;
	while (cnt < 2)
	{
		if (*hex < 10)
			*hex = *hex + 48;
		else
			*hex = *hex + 87; //ascii code for a is 97
		hex++;    
		cnt++;
	}
	hex = original_hex;
}

void	ft_putstr_non_printable(char *str)
{
	char	*original_str;
	char	hex[2];

	hex[0] = 0;
	hex[1] = 0;
	original_str = str;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 127)
		{
			write(1, "\\", 1);
			get_hexstring(str, hex);
			write(1, hex, 1);
			write(1, hex + 1, 1);
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

int main(){
	char str1[1000] = "Cooucou\ntu vas bien ?";
	ft_putstr_non_printable(str1);
}
