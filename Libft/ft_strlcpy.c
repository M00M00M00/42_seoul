/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:50:03 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 12:55:09 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	int		i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[i++] != '\0')
		len_src++;
	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
