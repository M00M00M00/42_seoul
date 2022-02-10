/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:12:34 by mukim             #+#    #+#             */
/*   Updated: 2022/02/10 15:28:20 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	matching(char *str, char *to_find, int cnt, int len_to_find)
{
	int	cnt_find;

	cnt_find = 0;
	while (cnt_find < len_to_find)
	{
		if (str[cnt] == to_find[cnt_find])
		{
			cnt++;
			cnt_find++;	
		}
		else
			break ;
	}
	if (cnt_find == len_to_find)
		return (1);
	return (0);
}


char	*ft_strstr(char *str, char *to_find)
{
	char	*original_find;
	int		len_to_find;
	int		cnt;

	cnt = 0;
	len_to_find = 0;
	original_find = to_find;
	while (*to_find != '\0')
	{
		len_to_find++;
		to_find++;
	}
	if (len_to_find == 0)
		return (str);
	else
	{
		to_find = original_find;
		while (str[cnt] != '\0')
		{
			if (matching(str, to_find, cnt, len_to_find))
				return (str + cnt);
			cnt++;
		}
	}
	return (str + cnt);
}
