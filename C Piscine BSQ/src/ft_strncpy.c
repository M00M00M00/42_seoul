/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:24:00 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 23:27:30 by moo              ###   ########.fr       */
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
	}
	*dest = '\0';
	return (origin_dest);
}
