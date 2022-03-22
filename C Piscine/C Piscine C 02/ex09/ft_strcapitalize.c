/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:05:34 by mukim             #+#    #+#             */
/*   Updated: 2022/02/13 13:53:11 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*original_str;
	int		sw_first;

	original_str = str;
	sw_first = 1;
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'Z') && sw_first == 0)
			*str += 32;
		if (sw_first)
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
			sw_first = 0;
		}
		if (!((*str >= 'a' && *str <= 'z') || \
		(*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9')))
			sw_first = 1;
		str++;
	}
	str = original_str;
	return (str);
}
