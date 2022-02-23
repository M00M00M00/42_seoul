# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moo <moo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/23 23:31:06 by moo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = bsq
SRCS =  ./src/funcs/ft_atoi.c\
		./src/funcs/ft_split.c\
		./src/funcs/ft_strcat.c\
		./src/funcs/ft_strlen.c\
		./src/funcs/ft_strncat.c\
		./src/funcs/ft_strncpy.c\
		./src/funcs/ft_strdup_til.c\
		./src/funcs/ft_strdup.c\
		./src/draw_ans.c\
		./src/find_best_pos.c\
		./src/main.c\
		./src/read_file.c\
		./src/read_stdin.c\
		./src/check_map.c\
		./src/check_str.c
OBJS = $(SRCS:.c=.o)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include
			 
all :		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean	all

.PHONY : all clean fclean re
