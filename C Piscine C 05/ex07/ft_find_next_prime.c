/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:15:51 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 17:54:35 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(unsigned int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	unsigned int	i;

	i = nb;

	if (i <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime1(i))
			return (i);
		i++;
	}
}
