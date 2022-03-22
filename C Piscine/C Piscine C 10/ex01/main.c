/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:57:50 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 11:19:07 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *str);
void	ft_puterror(char *str);

void	print_content(int fd)
{
	char	buff[1024];

	while (read(fd, buff, 1) > 0)
	{
		write(1, buff, 1);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	int	i;
	int	fd;

	i = 1;
	if (ac <= 1)
		return (0);
	if (ac > 1)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
			{
				ft_puterror("cat: ");
				ft_puterror(basename(av[i]));
				ft_puterror(": ");
				ft_puterror(strerror(errno));
				ft_puterror("\n");
				close(fd);
			}
			else
				print_content(fd);
			i++;
		}
	}
}
