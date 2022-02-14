/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:35:03 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 20:41:44 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_things(int **table, int **bits, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	free(table);
	i = 0;
	while (i < 2)
	{
		free(bits[i]);
		i++;
	}
	free(bits);
}
