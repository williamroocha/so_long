NAME = so_long

SRC := $(wildcard src/*.c) \
       $(wildcard includes/get_next_line/*.c)

OBJ := $(patsubst src/%.c,obj/%.o,$(filter-out includes/get_next_line/%.c,$(SRC))) \
       $(patsubst includes/get_next_line/%.c,obj/%.o,$(filter includes/get_next_line/%.c,$(SRC)))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./includes/mlx_linux
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(NAME)
	@echo "so_long compiled"

obj/%.o: src/%.c | obj
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: includes/get_next_line/%.c | obj
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf obj
	@echo "so_long cleaned"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "so_long fcleaned"

re: fclean all

obj: ; @mkdir -p $@

.PHONY: all clean fclean re
