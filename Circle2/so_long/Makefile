.PHONY: 		clean fclean re norm

NAME = so_long

CC = gcc

# ifeq ($(shell uname),Linux)
   # Linux-specific commands
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
	CFLAGS = -Wall -Wextra -Werror -ggdb
	MAKEFLAGS	+= --no-print-directory -s
# else
#    # Mac OS X-specific commands
# 	CFLAGS = -Wall -Wextra -Werror
# 	MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm
# endif

DISPLAY = @printf

# COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
DEFAULT		= \033[0m
SUPPR		= \r\033[2K

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

MLX_A		= libmlx.a
MLX_DIR 	= mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))

PRINT_A		= libftprintf.a
PRINT_DIR 	= ft_printf/
PRINT		= $(addprefix $(PRINT_DIR), $(PRINT_A))

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/game/ft_game_init.c \
      $(SRC_DIR)/game/ft_window.c \
	  $(SRC_DIR)/game/ft_open_imgs.c \
	  $(SRC_DIR)/game/ft_wall.c \
	  $(SRC_DIR)/game/ft_wall_bis.c \
	  $(SRC_DIR)/game/ft_move.c \
	  $(SRC_DIR)/game/ft_update.c \
	  $(SRC_DIR)/game/ft_move_sprite.c \
	  $(SRC_DIR)/game/ft_wall_matrix.c \
	  $(SRC_DIR)/game/ft_anim.c \
	  $(SRC_DIR)/game/ft_put_sprite.c \
	  $(SRC_DIR)/game/ft_sprite_obj.c \
	  $(SRC_DIR)/game/ft_ending.c \
      $(SRC_DIR)/create_map/ft_create_map.c \
      $(SRC_DIR)/create_map/ft_map_init.c \
      $(SRC_DIR)/create_map/ft_is_valid.c \
      $(SRC_DIR)/create_map/ft_map_info.c \
	  $(SRC_DIR)/create_map/ft_wall_valid.c \
	  $(SRC_DIR)/create_map/ft_objects_valid.c \
	  $(SRC_DIR)/create_map/ft_path_valid.c \
      $(SRC_DIR)/gnl/get_next_line.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINT) $(MLXFLAGS) $(MLX) -o $(NAME)
	@echo "\033[1;34mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl $(OBJ_DIR)/game
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@

lib:
	@make -C ./libft

norm:
	@if ! norminette ./game ./create_map ./gnl ./libft ./ft_printf | grep -v "OK" > /dev/null; then \
		echo "\033[1;32mNorminette valide ! ✔️\033[0m"; \
	else \
		norminette ./game ./create_map ./gnl ./libft ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
	fi

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	@rm -f $(NAME)

re: fclean norm all
