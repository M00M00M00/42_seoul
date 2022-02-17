CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all :		$(TARGET)

$(TARGET):	$(OBJS)
			ar rc $(TARGET) $(OBJS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(TARGET)

re :		fclean	all
