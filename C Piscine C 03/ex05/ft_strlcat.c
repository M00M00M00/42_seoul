/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:44 by mukim             #+#    #+#             */
/*   Updated: 2022/02/08 21:45:15 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	find_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*original_dest;
	unsigned int	cnt;
	unsigned int	ans;
	unsigned int	len_dest;
	unsigned int	len_src;

	cnt = 0;
	len_dest = find_len(dest);
	len_src = find_len(src);
	ans = len_dest + len_src;
	original_dest = dest;
	if (len_dest > size)
		return (len_src + size);
	dest += find_len(dest);
	while (*src != '\0' && cnt < (size - len_dest - 1))
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	*dest = '\0';
	return (len_dest + len_src);
}
