/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:11 by mukim             #+#    #+#             */
/*   Updated: 2022/02/14 15:08:25 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cnt;
	unsigned int	len_src;

	cnt = 0;
	len_src = 0;
	if (n < 1)
		return (0);
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
	return (len_src);
}
