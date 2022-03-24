# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 15:04:34 by mukim             #+#    #+#              #
#    Updated: 2022/03/24 17:10:24 by mukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a
FILES = ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strrchr \
		ft_tolower \
		ft_toupper \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))
OBJS = $(SRCS:.c=.o)

.c.o :		$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<
			 
all :		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean	all

.PHONY : all clean fclean re
