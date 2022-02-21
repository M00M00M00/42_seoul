/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:02:08 by mukim             #+#    #+#             */
/*   Updated: 2022/02/21 21:27:41 by mukim            ###   ########.fr       */
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
	int	k;

	i = 0;
	while (str[i] != '\n')
		i++;
	params->col_num = i;
	printf("%d\n",params->col_num);
	printf("%d\n",params->row_num);
	map = (char **) malloc(sizeof(char *) * (params->row_num + 1));
	while (i < params->row_num + 1)
		map[i++] = (char *) malloc(sizeof(char) * (params->col_num + 1));
	map[--i][0] = 0;
	i = 0;
	k = 0;
	printf("%s\n", str);
	while (str[k] && str[k - 1])
	{
		j = 0;
		while (str[k] != '\n' && str[k] != '\0')
			map[i][j++] = str[k++];
		k++;
		map[i][j] = 0;
		i++;
	}
}
