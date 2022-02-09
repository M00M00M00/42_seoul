#include <unistd.h>
#include <stdio.h>
void	print_pointer(unsigned long p)
{
	int	cnt;
	char	hexp[100];

	cnt = 0;
	while (cnt < 16)
	{
		hexp[cnt] = p % 16;
		p /= 16;
		cnt++;
	}
	cnt = 0;
	while (cnt < 16)
	{
		if (hexp[cnt] < 10)
			hexp[cnt] = hexp[cnt] + 48;
		else
			hexp[cnt] = hexp[cnt] + 87; //ascii code for a is 97
		cnt++;
	}
	cnt--;
	while (cnt > 0)
	{
		write(1, &hexp[cnt], 1);
		cnt--;
	}
	write(1, ":", 1);
}

void	get_hexstring(char *str)
{
	int	cnt;
	char	hexh[100];

	cnt = 0;
	hexh[0] = *str / 16;
	hexh[1] = *str % 16;
	while (cnt < 2)
	{
		if (hexh[cnt] < 10)
			hexh[cnt] += 48;
		else
			hexh[cnt] += 87; //ascii code for a is 97    
		cnt++;
	}
	write(1, &hexh[0], 1);
	write(1, &hexh[1], 1);
}

void	print_hexchar(char *str)
{
	int	cnt;
	char	*original_str;

	cnt = 0;
	original_str = str;
	while(cnt < 16 && *str != '\0')
	{
		if (cnt % 2 == 0)
			write(1, " ", 1);
		get_hexstring(str);
		str++;
		cnt++;
	}
	if (cnt != 16 && cnt % 2 == 1)
		write(1, "       ", 7);
	else if (cnt != 16)
		write(1, "     ", 5);
	write(1, " ", 1);
	str = original_str;
}

char	*print_string(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0' && cnt < 16)
	{
		if (*str >= 32 && *str <= 127)
		{
			write(1, str, 1);
			str++;
			cnt++;
		}
		else
		{
			write(1, ".", 1);
			str++;
			cnt++;
		}
	}
	return(str);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cnt;
	char	*sw;

	sw = addr;
	cnt = 0;
	if (size != 0)
	{
		while (*sw != '\0')
		{
			print_pointer((unsigned long) sw);
			print_hexchar(sw);
			print_string(sw);
			if (*sw != '\0')
				write(1, "\n", 1);
				sw += 16;
		}
	}
	return (addr);
}

int	main()
{
	char str[100] = "Bonjour les aminasdf asdfsdfdf dfdsaasfaaaaa";
	ft_print_memory(str,55);
}		
