/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:24:00 by mukim             #+#    #+#             */
/*   Updated: 2022/02/06 20:24:02 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*origin_dest;
	int		cnt;
	int		normal_n;

	normal_n = n;
	cnt = 0;
	origin_dest = dest;
	while (cnt < normal_n)
	{
		*dest = *src;
		cnt++;
		dest++;
		src++;
	}
	return (origin_dest);
}
