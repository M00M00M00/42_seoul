/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:14:52 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 15:14:54 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ans;
	int	cnt;

	ans = 1;
	cnt = 1;
	if (nb < 0)
		return (0);
	while (cnt < nb + 1)
	{
		ans *= cnt;
		cnt++;
	}
	return (ans);
}
