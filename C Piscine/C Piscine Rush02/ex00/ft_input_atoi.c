/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:58:23 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 18:35:27 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_input_atoi(char **argv)
{
	int	minus;
	int	return_value;

	minus = 1;
	return_value = 0;
	while (*argv[1] == ' ' || *argv[1] == '\t' || *argv[1] == '\n' \
			|| *argv[1] == '\v' || *argv[1] == '\f' || *argv[1] == '\r')
		argv[1]++;
	if (*argv[1] == '+' || *argv[1] == '-')
	{
		if (*argv[1] == '-')
			minus *= -1;
		argv[1]++;
	}
	while (*argv[1] == '0')
		argv[1]++;
}
