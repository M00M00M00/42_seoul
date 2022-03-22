/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:32:51 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 15:08:55 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	cnt;
	int	*arr;

	cnt = 0;
	if (min >= max)
	{
		*range = (void *) 0;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (arr == 0)
		return (-1);
	while (min < max)
	{
		arr[cnt] = min;
		cnt++;
		min++;
	}
	*range = arr;
	return (cnt);
}
