/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:24:00 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 13:48:59 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*origin_dest;
	unsigned int	cnt;

	cnt = 0;
	origin_dest = dest;
	while (cnt < n)
	{
		*dest = *src;
		dest++;
		cnt++;
		if (*src != '\0')
			src++;
	}
	return (origin_dest);
}
