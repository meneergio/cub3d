NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Clone minilibx-linux into this folder:
# git clone https://github.com/42Paris/minilibx-linux mlx_linux
MLX_DIR     = mlx_linux
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

INCLUDES    = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

SRC         = \
	src/main.c \
	src/parsing/cfg/cfg_init.c \
	src/parsing/cfg/cfg_free.c \
	src/parsing/error.c \
	src/parsing/input/free_lines.c \
	src/parsing/input/read_file_to_str.c \
	src/parsing/input/split_lines.c \
	src/parsing/scan/skip_spaces.c \
	src/parsing/scan/parse_id.c \
	src/parsing/scan/is_map_line.c \
	src/parsing/scan/find_map_start.c \
	src/parsing/elements/parse_elements.c \
	src/parsing/elements/parse_tex_line.c \
	src/parsing/elements/parse_color_line.c \
	src/parsing/elements/validate_cfg_complete.c \
	src/parsing/map/parse_map_grid.c \
	src/parsing/map/parse_map_padding.c \
	src/parsing/map/parse_map_validate.c \
	src/parsing/map/parse_map_closed.c \
	src/parsing/wrapper/parse_cub.c \
	src/game/game_start.c \
	src/game/game_destroy.c \
	src/mlx/mlx_init.c \
	src/mlx/mlx_hooks.c \
	src/mlx/mlx_loop.c \
	src/texture/tex_load.c \
	src/render/render.c \
	src/render/ceiling_floor.c \
	src/render/draw_column.c \
	src/raycast/raycast.c \
	src/raycast/dda.c \
	src/player/move.c \
	src/player/rotate.c \

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
