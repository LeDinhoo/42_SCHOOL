.PHONY: 		clean fclean re

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

MLX_A		= libmlx.a
MLX_DIR 	= mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/display_game/ft_game_init.c \
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

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) $(MLX) -o $(NAME)
	@echo "\033[1;34mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl $(OBJ_DIR)/display_game
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	@rm -f $(NAME)

re: fclean all
