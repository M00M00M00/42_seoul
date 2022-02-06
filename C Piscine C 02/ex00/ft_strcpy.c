/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:24:10 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 20:24:13 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*origin_dest;
	int		cnt;

	cnt = 0;
	origin_dest = dest;
	while (1)
	{
		*dest = *src;
		if (*src == '\0')
			cnt++;
		if (cnt == 1)
			break ;
		dest++;
		src++;
	}
	return (origin_dest);
}
