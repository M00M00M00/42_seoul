/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:23:09 by mukim             #+#    #+#             */
/*   Updated: 2022/02/22 17:11:33 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_content(char *file_name)
{
	char	buff[1024];
	int		fd;
	
	fd = open(file_name, O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		write(1, buff, 1);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	int	fb;
	
	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fb = open(argv[1], O_RDONLY);
	if (fb == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	print_content(argv[1]);
	return (0);
}
