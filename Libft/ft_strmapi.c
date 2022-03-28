/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:03:52 by mukim             #+#    #+#             */
/*   Updated: 2022/03/27 16:13:31 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	char			*ss;
	unsigned int	idx;

	len_s = ft_strlen(s);
	idx = 0;
	ss = (char *)malloc(sizeof(*s) * (len_s + 1));
	if (!ss)
		return (0);
	while (idx < len_s)
	{
		ss[idx] = f(idx, s[idx]);
		idx++;
	}
	ss[idx] = 0;
	return (ss);
}
