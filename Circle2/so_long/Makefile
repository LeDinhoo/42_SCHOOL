.PHONY: 		clean fclean re norm

NAME = so_long

CC = gcc

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
CFLAGS = -Wall -Wextra -Werror -ggdb

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

HEADERS = headers/so_long.h \
			headers/map.h	\


all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINT) $(MLXFLAGS) $(MLX) -o $(NAME)
	@echo "Compilation terminée avec succès ! ✔️"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl $(OBJ_DIR)/game
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@

lib:
	@make -C ./libft
	@make -C ./ft_printf

norm:
	@if ! norminette ./game ./create_map ./gnl ./libft ./ft_printf | grep -v "OK" > /dev/null; then \
		echo "Norminette valide ! ✔️"; \
	else \
		norminette ./game ./create_map ./gnl ./libft ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
	fi

clean:
	@echo "Suppression des fichiers objets..."
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Suppression du programme final..."
	@rm -f $(NAME)

re: fclean norm all
