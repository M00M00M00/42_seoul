/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:32:31 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 13:47:56 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_til(char *src, char sep)
{
	int		i;
	char	*cp;

	i = 0;
	while (src[i] != sep || src[i] != '\0')
		i++;
	cp = malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != sep || src[i] != '\0')
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
