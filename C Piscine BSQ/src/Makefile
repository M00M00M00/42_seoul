# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/21 20:33:12 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = a.out
SRCS = $(wildcard ./*.c) 
OBJS = $(SRCS:.c=.o)

all :		$(TARGET)
			
$(TARGET):	
			$(CC) -o $(TARGET) $(SRCS)
clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(TARGET)

re :		fclean	all
