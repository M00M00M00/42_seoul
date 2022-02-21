/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:26:48 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 15:45:11 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_sw(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	sw;

	sw = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			sw = 1;
		else if (f(tab[i], tab[i + 1]) < 0)
			sw = -1;
		i++;
	}
	return (sw);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	sw;

	i = 0;
	if (length < 2)
		return (1);
	sw = find_sw(tab, length, f);
	while (i < length - 1)
	{
		if (sw == 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		}
		else if (sw == -1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
		}
		i++;
	}
	return (1);
}
