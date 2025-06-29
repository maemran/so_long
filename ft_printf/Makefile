CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_hexa_lower.c ft_hexa_upper.c ft_pointer.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME) $(OBJS)
re: fclean all

.PHONY: all clean fclean re
