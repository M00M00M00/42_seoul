# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/20 19:55:45 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = rush-02
SRCS = $(wildcard ./*.c)

all :		$(TARGET)

$(TARGET):	
			$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(TARGET)

re :		fclean	all
