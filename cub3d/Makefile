NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I includes -I $(LIBFT_DIR)

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

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
