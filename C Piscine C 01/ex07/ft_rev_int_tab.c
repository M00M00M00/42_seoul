/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:34:53 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 18:34:55 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*left_p;
	int	*right_p;
	int	temp;

	left_p = tab;
	right_p = tab + size - 1;
	temp = 0;
	while (left_p < right_p)
	{
		temp = *left_p;
		*left_p = *right_p;
		*right_p = temp;
		left_p++;
		right_p--;
	}
}
