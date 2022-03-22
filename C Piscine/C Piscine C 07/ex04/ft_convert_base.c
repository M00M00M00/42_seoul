/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:21 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 15:08:56 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	ft_atoi_base(char *str, char *base);
int	find_len(char *str);
int	check_base(char *base);

char	*make_arr(long long nbr, char *base, int i, int j)
{
	char	*arr_to;
	int		arr_from[1000];
	int		base_len;

	arr_to = malloc(sizeof(char) * 1000);
	base_len = find_len(base);
	if (nbr < 0)
	{
		nbr *= -1;
		arr_to[j++] = '-';
	}
	while (nbr > 0)
	{
		arr_from[i++] = nbr % base_len;
		nbr /= base_len;
	}
	while (--i >= 0)
		arr_to[j++] = base[arr_from[i]];
	arr_to[j] = '\0';
	return (arr_to);
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	int		len_base;
	char	*ans;

	ans = malloc(sizeof(char) * 2);
	if (!(ans))
		return (0);
	len_base = find_len(base);
	if (nbr == 0)
	{
		ans[0] = base[0];
		ans[1] = '\0';
		return (ans);
	}
	free(ans);
	return (make_arr(nbr, base, 0, 0));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	len_base_from;
	int	len_base_to;

	len_base_from = find_len(base_from);
	len_base_to = find_len(base_to);
	if (len_base_from <= 1 || len_base_to <= 1 \
	|| !check_base(base_from) || !check_base(base_to))
		return (0);
	i = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(i, base_to));
}
