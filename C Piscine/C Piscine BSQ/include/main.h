/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:33 by mukim             #+#    #+#             */
/*   Updated: 2022/02/23 20:01:09 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

char	*read_file(t_map *map, char *filename);
char	**ft_split(char *str, char *charset, int col_num, int row_num);
t_pos	find_best_pos(int **map_int, int row_num, int col_num);
void	draw_ans(char **map, t_map params, t_pos best_pos);
char	*read_stdin(t_map *map);
int		check_str(char *str, t_map parmas);

#endif
