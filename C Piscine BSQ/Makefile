# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moo <moo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 10:54:19 by mukim             #+#    #+#              #
#    Updated: 2022/02/20 02:50:52 by moo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = a.out
SRCS = $(wildcard ./src/*.c) 
INCLUDES = $(wildcard ./include/*.h)
OBJS = $(SRCS:.c=.o)

all :		$(TARGET)
			$(CC) $(CFLAGS) $(TARGET) $(OBJS) -I include $(INCLUDES)

$(TARGET):	
			$(CC) -c $(SRCS) -I include $(INCLUDES)	
clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(TARGET)

re :		fclean	all
