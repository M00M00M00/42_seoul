# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/22 18:26:45 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = do-op
SRCS = ./ft_atoi.c ./ft_putnbr.c ./main.c ./operate.c
OBJS = $(SRCS:.c=.o)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all :		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean	all

.PHONY : all clean fclean re
