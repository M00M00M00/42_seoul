/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:59:07 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 18:40:40 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dict_check2(char *buff, int i, int count)
{
	while (i < count)
	{
		if (*buff < '0' && *buff > '9')
			return (0);
		while (*buff >= '0' && *buff <= '9')
			buff++;
		while ((*buff >= 9 && *buff <= 13) || *buff == ' ')
			buff++;
		if (*buff != ':')
			return (0);
		buff++;
		while ((*buff >= 9 && *buff <= 13) || *buff == ' ')
			buff++;
		while (*buff >= 32 && *buff <= 126)
			buff++;
		if (i != count - 1)
		{
			if (*buff != '\n')
				return (0);
		}
		buff++;
		i++;
	}
	return (1);
}

int	dict_check(char *buff, int i, int count)
{
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	return (dict_check2(buff, 0, count));
}
