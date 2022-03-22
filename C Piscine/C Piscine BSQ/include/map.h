/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:36 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 20:00:57 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		row_num;
	int		col_num;
	char	empty;
	char	obs;
	char	fill;
}t_map;

typedef struct s_pos
{
	int	x;
	int	y;
	int	content;
}t_pos;

#endif
