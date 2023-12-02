NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes/

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRC := $(addprefix $(SRC_DIR)/, \
	so_long.c \
) \
$(addprefix $(SRC_DIR)/action/, \
	closing_game.c \
	keypress.c \
	loop.c \
	register_hook.c \
) \
$(addprefix $(SRC_DIR)/build/, \
	build.c \
	build_characters.c \
	build_collectible.c	\
    build_coordinates.c \
    build_enemy.c \
    build_exit.c \
    build_game.c \
    build_map.c \
    build_mlx_itens.c \
    build_player.c \
    build_sprites.c \
    read_map.c \
) \
$(addprefix $(SRC_DIR)/draw/, \
	draw_background.c \
    draw_collectibles.c \
    draw_enemies.c \
    draw_exit.c \
    draw_player.c \
   	draw_ultils.c \
    player_movements.c \
) \
$(addprefix $(SRC_DIR)/util/, \
    check_map.c \
    check_map_characters.c \
    check_map_extension.c \
    check_map_walls.c \
    colision_walls.c \
    convert_lst_to_char.c \
    dead_player.c \
    directions.c \
    end_game.c \
    error_handler.c \
	finish_game.c \
	flood_fill.c \
) \
$(addprefix $(INC_DIR)/get_next_line/, \
	get_next_line.c \
	get_next_line_utils.c \
)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./includes/mlx_linux
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft $(MLXFLAGS)
	@echo "so_long compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -s -C $(MLX_DIR) > /dev/null 2>&1
	@echo "mlx compiled"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(MAKE) -s clean -C $(MLX_DIR) > /dev/null 2>&1
	@echo "so_long removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@echo "so_long removed"

re: fclean all

.PHONY: clean fclean all re
