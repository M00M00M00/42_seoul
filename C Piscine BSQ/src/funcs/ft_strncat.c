/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:24 by mukim             #+#    #+#             */
/*   Updated: 2022/02/08 17:12:26 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*original_dest;
	unsigned int	cnt;

	cnt = 0;
	original_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && cnt < nb)
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	*dest = '\0';
	return (original_dest);
}
