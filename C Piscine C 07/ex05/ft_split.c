/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:33:39 by mukim             #+#    #+#             */
/*   Updated: 2022/02/15 20:33:40 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_match(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] == charset[i])
		i++;
	if (charset[i] == '\0')
		return (1);
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	cnt;

	cnt = 1;
	while (*str)
	{
		if (is_match(str, charset))
			cnt++;
		str++;
	}
	str--;
	if (is_match(str, charset))
		cnt--;
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
		if (is_match(str, charset))
			str += find_len1(charset);
		ans[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ans;
	int		size_of_str;
	int		i;

	size_of_str = count_str(str, charset);
	ans = (char **) malloc(sizeof(char *) * (size_of_str));
	i = 0;
	while (i < size_of_str)
	{
		ans[i] = (char *) malloc(sizeof(char) * (find_len1(str) + 1));
		i++;
	}
	allocate_each(ans, str, charset, size_of_str);
	return (ans);
}
