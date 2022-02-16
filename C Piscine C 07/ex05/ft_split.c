/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:39 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 15:24:20 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_match(char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	cnt;

	cnt = 1;
	while (*str)
	{
		if (str[1] != '\0')
			if (is_match(str, charset) && !is_match(str + 1, charset))
				cnt++;
		str++;
	}
	return (cnt);
}

int	find_len1(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	allocate_each(char **ans, char *str, char *charset, int size_of_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_of_str)
	{
		j = 0;
		while (!is_match(str, charset) && *str != '\0')
		{
			ans[i][j] = *str;
			j++;
			str++;
		}
		while (is_match(str, charset))
			str++;
		ans[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ans;
	int		size_of_str;
	int		i;
	int		len_str;

	len_str = find_len1(str);
	size_of_str = count_str(str, charset);
	ans = malloc(sizeof(char *) * (size_of_str));
	i = 0;
	while (i < size_of_str)
	{
		ans[i] = malloc(sizeof(char) * (len_str + 1));
		i++;
	}
	allocate_each(ans, str, charset, size_of_str);
	return (ans);
}