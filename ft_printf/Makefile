# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:08:55 by mukim             #+#    #+#              #
#    Updated: 2022/05/17 15:58:05 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		src/ft_putlonglong_fd.c \
		src/ft_putpointer_fd.c \
		src/ft_putlowerhex_fd.c \
		src/ft_putupperhex_fd.c \
		src/ft_putuint_fd.c \


DEL_O = ft_putlonglong_fd.o \
		ft_putpointer_fd.o \
		ft_putlowerhex_fd.o \
		ft_putupperhex_fd.o \
		ft_putuint_fd.o


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

.c.o:		$(SRCS)
			$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		make bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	make clean -C ./libft
	rm -rf $(OBJS) $(DEL_O)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
