/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:04:54 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 20:01:06 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/func.h"
#include "../include/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char	*read_file(int fd, t_map *map);
void	make_map(char **map, char *str, t_map *params);

int	main()
{
	t_map params;
	int		fd;
	char	*str;
	char	**map;
	int		**map_int;
	int		i;

	i = 0;
	fd = open("../grid1.txt", O_RDONLY);
	str = read_file(fd, &params);
	// make_map(map, str, &params);
	// // while (map[i])
	// // {
	// // 	printf("%s\n", map[i++]);
	// // }
	// printf("%s\n", map[1]);
}