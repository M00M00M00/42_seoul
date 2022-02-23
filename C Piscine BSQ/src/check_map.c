/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:59:30 by mukim             #+#    #+#             */
/*   Updated: 2022/02/24 00:27:37 by moo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_overlap(char *str, int index)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = str[index++];
	c2 = str[index++];
	c3 = str[index];
	if (c1 == c2 || c2 == c3 || c3 == c1)
		return (0);
	if ((c1 < 32 || c1 > 126) || (c2 < 32 || c2 > 126) || (c1 < 32 || c1 > 126))
		return (0);
	return (1);
}

int	check_firstline(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i + 3])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!is_overlap(str, i))
		return (0);
	return (1);
}
