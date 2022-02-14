/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:29:35 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 21:08:07 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_cnt_left(int **table, int temp, int x, int y)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	while (i <= y)
	{
		if (temp < table[x][i])
		{
			cnt++;
			temp = table[x][i];
		}
		i++;
	}
	return (cnt);
}

int	get_cnt_up(int **table, int temp, int x, int y)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	while (i <= x)
	{
		if (temp < table[i][y])
		{
			cnt++;
			temp = table[i][y];
		}
		i++;
	}
	return (cnt);
}
