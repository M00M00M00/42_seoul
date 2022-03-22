/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjupa <sangjupa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:58:30 by sangjupa          #+#    #+#             */
/*   Updated: 2022/02/08 16:49:55 by sangjupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int		minus;
	int		return_value;

	minus = 1;
	return_value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		return_value = return_value * 10 + *str - '0';
		str++;
	}
	return (minus * return_value);
}
