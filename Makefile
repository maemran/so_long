CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =  put_string_to_win.c\
 		so_long.c\
		map_check.c\
		path_check.c\
		draw.c\
		move.c\

OBJ_DIR = OBJ
SRC_DIR = SRC
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = so_long
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MLXFLAGS = -L. -lmlx -lXext -lX11

all: LIBFT PRINTF $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) ./include/so_long.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT:
	make -C $(LIBFT_DIR)

PRINTF:
	make -C $(PRINTF_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -fr $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: re all clean fclean LIBFT PRINTF