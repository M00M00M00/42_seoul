/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:08 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 20:06:22 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/func.h"
#include "../include/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	make_map(char **map, char *str, t_map *params)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n')
		i++;
	params -> col_num = i;
	map = (char **) malloc(sizeof(char *) * (params->row_num + 1));
	while (i < params->row_num)
		map[i++] = (char *) malloc(sizeof(char) * (params->col_num + 1));
	*map[i] = 0;
	i = 0;
	while (i < params -> row_num)
	{
		j = 0;
		while (*str != '\n')
			map[i][j++] = *str++;
		str++;
		map[i][j] = 0;
		i++;
	}
	*map[i] = 0;
}
