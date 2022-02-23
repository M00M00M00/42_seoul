/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moo <moo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:30 by mukim             #+#    #+#             */
/*   Updated: 2022/02/24 00:54:46 by moo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset, int col_num, int row_num);
char	*ft_strdup_til(char *src, char sep);
char	*ft_strdup(char *src);
int		ft_concate(char **dest, char *src);

#endif
