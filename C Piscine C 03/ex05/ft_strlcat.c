/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:44 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 15:15:02 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = 0;
	len_src = 0;
	while (*dest != '\0')
	{
		dest++;
		len_dest++;
	}
	while (*src != 0 && len_dest + len_src + 1 < size)
	{
		*dest++ = *src++;
		len_src++;
	}
	while (*src != '\0')
	{
		len_src++;
		src++;
	}
	if (len_dest >= size)
		return (len_src + size);
	return (len_dest + len_src);
}
