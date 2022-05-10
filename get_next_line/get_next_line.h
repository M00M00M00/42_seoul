/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:54:39 by mukim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/10 17:35:54 by mukim            ###   ########.fr       */
=======
/*   Updated: 2022/04/27 14:11:36 by mukim            ###   ########.fr       */
>>>>>>> 87076f542f2069d7f5f78d9480e3ec5bf2d655f4
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_first_idx(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
<<<<<<< HEAD
=======
int		check_reminder(char **reminder, char **rtn);
int		check_buff(char *buff, char **reminder, int ret, char **rtn);
void	to_next_line(char *buff, char **reminder, int ret, char **rtn);
>>>>>>> 87076f542f2069d7f5f78d9480e3ec5bf2d655f4

#endif
