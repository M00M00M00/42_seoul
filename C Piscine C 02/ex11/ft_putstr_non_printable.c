#include <unistd.h>

void	f_strncpy(char *dest, char *src, unsigned int n)
{
	char	*origin_dest;
	int		cnt;
	int		normal_n;

	normal_n = n;
	cnt = 0;
	origin_dest = dest;
	while (cnt < normal_n)
	{
		*dest = *src;
		cnt++;
		dest++;
		src++;
	}
	dest = origin_dest;	
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[4];
	char	*original_str;
	char	for_print;

	original_str = str;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 127)
		{
			for_print = &*str
			write(1, "\\", 1);
			write(1, for_print, 1);
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
