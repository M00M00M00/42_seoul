/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:41:55 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 15:30:53 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*cp;

	i = 0;
	while (src[i])
		i++;
	cp = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_out;
	int			i;

	i = 0;
	if (ac < 0)
		return (0);
	s_out = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_out == 0)
		return (0);
	while (i < ac)
	{
		s_out[i].size = ft_strlen(av[i]);
		s_out[i].str = av[i];
		s_out[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_out[i].str = 0;
	return (s_out);
}
