/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:24:20 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 15:49:51 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*n_s1;
	unsigned char	*n_s2;
	int				i;

	n_s1 = (unsigned char *) s1;
	n_s2 = (unsigned char *) s2;
	i = 0;
	while (i < (int) n && (*n_s1 != '\0' || *n_s2 != '\0'))
	{
		if (*n_s1 != *n_s2)
			return (*n_s1 - *n_s2);
		n_s1++;
		n_s2++;
		i++;
	}
	if (i == (int) n)
		return (0);
	return (*n_s1 - *n_s2);
}
