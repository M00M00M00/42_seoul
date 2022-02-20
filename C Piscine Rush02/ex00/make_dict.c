/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:15:49 by mukim             #+#    #+#             */
/*   Updated: 2022/02/20 19:56:18 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "s_dict.h"
int	dict_check(char *buff, int i, int count);

int	open_dict_check(int fd, char *buff)
{
	char	*head;

	if (0 < fd)
	{
		read(fd, buff, 1024);
		close(fd);
	}
	else
	{
		write(1, "Dict Erorr\n", 11);
		return (0);
	}
	head = buff;
	if (!dict_check(head, 0, 0))
	{
		write(1, "Dict Erorr\n", 11);
		return (0);
	}
	return (1);
}

void	allocate_dict(t_dict *arr, char *buff, int i, int count)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (i < count)
	{
		j = 0;
		while (buff[k] != ':')
			arr[i].key[j++] = buff[k++];
		arr[i].key[j] = '\0';
		j = 0;
		k += 2;
		while (buff[k] != '\n' && buff[k] != '\0')
			arr[i].value[j++] = buff[k++];
		arr[i].value[j] = '\0';
		k++;
		i++;
	}
}

t_dict	*make_dict(int i, int count)
{
	char	buff[1024];
	int		fd;
	t_dict	*arr;

	fd = open("numbers.dict", O_RDONLY);
	if (!(open_dict_check(fd, buff)))
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	arr = (t_dict *)malloc(sizeof(t_dict) * count);
	i = 0;
	while (i < count)
	{
		arr[i].key = (char *) malloc (sizeof(char) * 100);
		arr[i].value = (char *) malloc (sizeof(char) * 100);
		i++;
	}
	allocate_dict(arr, buff, 0, count);
	return (arr);
}
