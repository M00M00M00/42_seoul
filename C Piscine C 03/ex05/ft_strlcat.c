/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:44 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 11:29:27 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	find_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_dest = find_len(dest);
	len_src = find_len(src);
	if (len_dest > size)
		return (len_src + size);
	while (*dest)
	{
		dest++;
	}
	while (*src && i + len_dest + 1< size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (len_dest + len_src);
}
