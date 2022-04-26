/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:54:12 by mukim             #+#    #+#             */
/*   Updated: 2022/04/26 18:59:24 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	to_next_line(char *buff, char **reminder, int ret, char **rtn)
{
	int		first_idx;
	char	*temp;

	first_idx = find_first_idx(*reminder, '\n');
	if (first_idx < ret)
	{
		temp = ft_substr(*reminder, first_idx + 1, ret - first_idx - 1);
		free(*reminder);
		*reminder = temp;
	}
	buff[first_idx + 1] = 0;
	if (!*rtn)
		*rtn = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(*rtn, buff);
		free(*rtn);
		*rtn = temp;
	}
}

int	check_buff(char *buff, char **reminder, int ret, char **rtn)
{
	int		i;
	char	*temp;

	buff[ret] = 0;
	i = find_first_idx(*reminder, '\n');
	if (i != -1)
	{
		to_next_line(buff, reminder, ret, rtn);
		return (1);
	}
	if (!*rtn)
		*rtn = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(*rtn, buff);
		free(*rtn);
		*rtn = temp;
	}
	return (0);
}

int	check_reminder(char **reminder, char **rtn)
{
	int		len_re;
	int		first_idx;
	char	*temp;

	first_idx = find_first_idx(*reminder, '\n');
	len_re = ft_strlen(*reminder);
	if (first_idx != -1)
	{
		if (first_idx < len_re - 1)
		{
			*rtn = ft_substr(*reminder, 0, first_idx + 1);
			temp = ft_substr(*reminder, first_idx + 1, len_re - first_idx - 1);
			free(*reminder);
			*reminder = temp;
			return (1);
		}
		*rtn = *reminder;
		*reminder = 0;
		return (1);
	}
	temp = ft_strjoin("", *reminder);
	free(*reminder);
	*reminder = 0;
	*rtn = temp;
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*rtn;
	static char	*reminder;
	int			ret;

	rtn = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (reminder && check_reminder(&reminder, &rtn))
		return (rtn);
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		if (check_buff(buff, &reminder, ret, &rtn))
		{
			free(buff);
			return (rtn);
		}
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (rtn);
}
