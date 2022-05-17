/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:56:50 by mukim             #+#    #+#             */
/*   Updated: 2022/05/17 16:56:02 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./libft/libft.h"

void	type_print(char c, va_list *ap)
{
	if (c == 'c')
		ft_putchari_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'p')
		ft_putpointer_fd(va_arg(*ap, void *), 1);
	else if (c == 'd')
		ft_putlonglong_fd(va_arg(*ap, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (c == 'u')
		ft_putuint_fd(va_arg(*ap, int), 1);
	else if (c == 'x')
		ft_putlowerhex_fd(va_arg(*ap, int), 1);
	else if (c == 'X')
		ft_putupperhex_fd(va_arg(*ap, int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return ;
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	idx;

	idx = -1;
	va_start(ap, input);
	while (input[++idx])
	{
		if (input[idx] == '%')
		{
			idx++;
			type_print(input[idx], &ap);
		}
		else
			ft_putchar_fd(input[idx], 1);
	}
	va_end(ap);
	return (0);
}
