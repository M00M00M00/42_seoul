/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:03:30 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 16:33:48 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap1(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (tab[size])
		size++;
	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap1(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i--;
	}
}
