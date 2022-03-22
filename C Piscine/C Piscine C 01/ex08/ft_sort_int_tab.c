/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:35:05 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 18:35:07 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sorting(int cnt1, int cnt2, int *tab)
{
	int	temp;
	int	*origin_tab;

	origin_tab = tab;
	temp = 0;
	while (cnt2 > 0)
	{
		while (cnt1 < cnt2)
		{
			if (*tab > *(tab + 1))
			{
				temp = *tab;
				*tab = *(tab + 1);
				*(tab + 1) = temp;
			}
			tab++;
			cnt1++;
		}
		tab = origin_tab;
		cnt1 = 0;
		cnt2--;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	cnt2 = size - 1;
	sorting(cnt1, cnt2, tab);
}
