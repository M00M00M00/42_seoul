/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:04:34 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 15:04:35 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	else
	{
		while (*str != '\0')
		{
			if (*str < '0' || *str > '9')
				return (0);
			str++;
		}
	}
	return (1);
}