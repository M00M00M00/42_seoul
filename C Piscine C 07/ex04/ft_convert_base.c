/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:21 by mukim             #+#    #+#             */
/*   Updated: 2022/02/15 20:33:23 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	find_len(char *str);
int	check_base(char *base);

char	*make_arr(long long nbr, char *base, int i, int j)
{
	long long	len_base;
	char		*arr1;
	char		*arr2;
	int			sw_minus;

	sw_minus = 0;
	arr1 = (char *) malloc(sizeof(char) * 100);
	arr2 = (char *) malloc(sizeof(char) * 100);
	len_base = find_len(base);
	if (nbr < 0)
	{
		nbr *= -1;
		sw_minus = 1;
	}
	while (nbr > 0)
	{
		arr1[i++] = nbr % len_base;
		nbr /= len_base;
	}
	if (sw_minus)
		arr2[j++] = '-';
	while (--i >= 0)
		arr2[j++] = base[(int) arr1[i]];
	arr2[j] = '\0';
	return (arr2);
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	int	len_base;

	len_base = find_len(base);
	if (len_base > 1 && check_base(base))
	{
		if (nbr == 0)
			return (&base[0]);
		return (make_arr(nbr, base, 0, 0));
	}
	return (0);
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
