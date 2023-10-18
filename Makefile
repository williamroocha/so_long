NAME = so_long

SRC = src/*.c

OBJ = $(SRC:.c=.o)

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

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f $(OBJ)
	@echo "so_long cleaned"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "so_long fcleaned"

re: fclean all

.PHONY: all clean fclean re
