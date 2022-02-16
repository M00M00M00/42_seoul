/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:06:09 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 16:12:45 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	print_pointer(unsigned long p)
{
	int		cnt;
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
			hexp[cnt] = hexp[cnt] + 87;
		cnt++;
	}
	while (cnt > 0)
	{
		write(1, &hexp[cnt - 1], 1);
		cnt--;
	}
	write(1, ":", 1);
}

void	get__hexstring(unsigned char str)
{
	int				cnt;
	unsigned char	hexh[100];

	cnt = 0;
	hexh[0] = str / 16;
	hexh[1] = str % 16;
	while (cnt < 2)
	{
		if (hexh[cnt] < 10)
			hexh[cnt] += 48;
		else
			hexh[cnt] += 87;
		cnt++;
	}
	write(1, &hexh[0], 1);
	write(1, &hexh[1], 1);
}

void	print_hexchar(unsigned char *str, unsigned int cnt, unsigned int size)
{
	unsigned int	cnt_here;

	cnt_here = 0;
	while (str[cnt_here] != '\0' && cnt_here < 16 && cnt + cnt_here < size)
	{
		if (cnt_here % 2 == 0)
			write(1, " ", 1);
		get__hexstring(str[cnt_here]);
		cnt_here++;
	}
	if (cnt_here != 16)
	{
		if (cnt_here == 15)
			write(1, "  ", 2);
		else if (cnt_here % 2 == 1)
			write(1, "       ", 7);
		else
			write(1, "     ", 5);
	}
	write(1, " ", 1);
}

unsigned int	print_string(unsigned char *str,
							unsigned int cnt, unsigned int size)
{
	unsigned int	cnt_here;

	cnt_here = 0;
	while (str[cnt_here] != '\0' && cnt_here < 16 && cnt + cnt_here < size)
	{
		if (str[cnt_here] >= 32 && str[cnt_here] <= 127)
		{
			write(1, &str[cnt_here], 1);
			cnt_here++;
		}
		else
		{
			write(1, ".", 1);
			cnt_here++;
		}
	}
	return (cnt_here);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cnt;
	unsigned char	*sw;
	unsigned char	cnt_temp;

	sw = (unsigned char *) addr;
	cnt = 0;
	cnt_temp = 16;
	if (size != 0)
	{
		while (cnt_temp == 16 && *sw != '\0' && cnt <= size)
		{
			print_pointer((unsigned long) sw);
			print_hexchar(sw, cnt, size);
			cnt_temp = print_string(sw, cnt, size);
			cnt += cnt_temp;
			sw += cnt_temp;
			write(1, "\n", 1);
		}
	}
	return (addr);
}
