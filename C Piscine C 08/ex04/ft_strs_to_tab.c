/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:41:55 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 17:35:48 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*cp;

	i = 0;
	while (src[i])
		i++;
	cp = malloc(sizeof(char) * i);
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

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_out;
	int			i;

	i = 0;
	s_out = malloc(sizeof(t_stock_str) * ac);
	if (s_out == 0)
		return (0);
	while (i < ac)
	{
		s_out[i].size = ft_strlen(av[i]);
		s_out[i].str = av[i];
		s_out[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (s_out);
}
