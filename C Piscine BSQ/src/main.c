/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:04:54 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 21:32:17 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/func.h"
#include "../include/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file(t_map *map);
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
	
	str = read_file(&params);
	make_map(map, str, &params);
}
