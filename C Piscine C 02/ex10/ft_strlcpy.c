/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:11 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 13:10:46 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	char			*origin_dest;
	unsigned int	cnt;
	unsigned int	len_src;

	cnt = 0;
	len_src = 0;
	origin_dest = dest;
	while (src[cnt] != '\0')
	{
		cnt++;
		len_src++;
	}
	cnt = 0;
	while (cnt < n - 1 && *src != '\0')
	{
		*dest = *src;
		cnt++;
		dest++;
		src++;
	}
	*dest = '\0';
	dest = origin_dest;
	return (len_src);
}
