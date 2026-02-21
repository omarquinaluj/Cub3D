NAME			=	cub3D

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
MLX_FLAGS		=	-Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

PARSE_DIR		=	SRC/Parsing
GAME_DIR	=	SRC/game

SRC				=	SRC/Main.c \
					SRC/Error.c \
					SRC/Free.c \
					$(PARSE_DIR)/parse.c \
					$(PARSE_DIR)/check_colors.c \
					$(PARSE_DIR)/check_texture.c \
					$(PARSE_DIR)/check_cub.c \
					$(PARSE_DIR)/check_map.c \
					$(PARSE_DIR)/check_spaces.c \
					$(PARSE_DIR)/check_flood_fill.c\
					$(PARSE_DIR)/set_texture_line.c\
					$(GAME_DIR)/rendering.c \
					$(GAME_DIR)/init_ray.c \
					$(GAME_DIR)/calc_draw.c \
					$(GAME_DIR)/nsew.c\
					$(GAME_DIR)/remaster.c \
					$(GAME_DIR)/control_keys.c \
					$(GAME_DIR)/types_moves.c \
					$(GAME_DIR)/draw_rays.c \
					$(GAME_DIR)/set_texture.c \
					$(GAME_DIR)/minimap.c


OBJ				=	$(SRC:.c=.o)

LIBFT_DIR	=	INCLUDES/Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	INCLUDES/get_next_line
GNL			=	$(GNL_DIR)/gnl.a

MLX_DIR		=	mlx
MLX			=	$(MLX_DIR)/libmlx.a

all: $(NAME)

r: fclean all
	./$(NAME) maps/valid/map.cub

run: ./cub3D

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(GNL):
	$(MAKE) -s -C $(GNL_DIR) CFLAGS="$(CFLAGS)"

$(MLX):
	$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(LIBFT) $(GNL) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) $(OBJ) $(LIBFT) $(GNL) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -s -C $(LIBFT_DIR) clean
	$(MAKE) -s -C $(GNL_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -s -C $(LIBFT_DIR) fclean
	$(MAKE) -s -C $(GNL_DIR) fclean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re run r