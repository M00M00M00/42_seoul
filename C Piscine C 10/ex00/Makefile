# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/19 15:25:09 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = ft_display_file
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all :		$(TARGET)

$(TARGET):	$(OBJS)
			$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(TARGET)

re :		fclean	all
