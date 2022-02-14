/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:34 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 11:16:15 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i + j] == to_find[j])
		{
			while (to_find[j])
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
			if (!(to_find[j]))
				return (str + i);
		}
		i++;
	}
	return (str + i);
}
