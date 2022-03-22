/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:57:50 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 11:43:32 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*read_file(char *filename);

void	print_content(int bytes, char *content)
{
	while (content)
		content++;
	content -= bytes;
	ft_putstr(content);
	return ;
}

int	main(int ac, char **av)
{
	int		i;
	int		bytes;
	char	*content;

	i = 1;
	if (ac != 3)
		return (0);
	bytes = ft_atoi(av[2]);
	content = read_file(av[3]);
	if (!content)
		return (0);
	print_content(bytes, content);
	return (0);
}
