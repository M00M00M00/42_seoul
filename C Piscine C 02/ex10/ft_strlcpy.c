/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:11 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 15:07:14 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	char			*origin_dest;
	unsigned int	cnt;

	cnt = 0;
	origin_dest = dest;
	while (cnt < n - 1 && *src != '\0')
	{
		*dest = *src;
		cnt++;
		dest++;
		src++;
	}
	while (*src != '\0')
	{
		src++;
		cnt++;
	}
	*dest = '\0';
	dest = origin_dest;
	return (cnt);
}
