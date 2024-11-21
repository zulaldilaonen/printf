NAME =libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = ft_p.c ft_printf.c ft_putchar.c ft_putnbr.c \
       ft_putstr.c ft_x.c ft_xx.c ft_u.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re