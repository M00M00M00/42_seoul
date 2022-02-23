/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:33:41 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 12:01:38 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_puterror(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strcat(char *dest, char *src);


char	*read_til(int fd, char sep, int i)
{
	char	*buff;
	char	*temp;
	char	*return_char;

	buff = malloc(sizeof(char));
	if (!(buff))
		return (0);
	return_char = malloc(sizeof(char));
	if (!(return_char))
		return (0);
	*return_char = '\0';
	while (read(fd, buff, 1) > 0 && *buff != sep)
	{
		temp = return_char;
		return_char = malloc(sizeof(char) * (i++ + 1));
		if (!(return_char))
			return (0);
		return_char[0] = '\0';
		ft_strcat(return_char, temp);
		ft_strncat(return_char, buff, 1);
		free(temp);
	}
	free(buff);
	return_char[i] = '\0';
	return (return_char);
}

char	*read_file(char *filename)
{
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("cat: ");
		ft_puterror(basename(filename));
		ft_puterror(": ");
		ft_puterror(strerror(errno));
		ft_puterror("\n");
		close(fd);
		return (0);
	}
	str = read_til(fd, '\0', 1);
	close(fd);
	if (!(str))
		return (0);
	return (str);
}
