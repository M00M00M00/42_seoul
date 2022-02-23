/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_til.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:32:31 by mukim             #+#    #+#             */
/*   Updated: 2022/02/24 00:06:38 by moo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_til(char *src, char sep)
{
	int		i;
	char	*cp;

	i = 0;
	while (src[i] != sep && src[i] != '\0')
		i++;
	cp = malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != sep && src[i] != '\0')
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
