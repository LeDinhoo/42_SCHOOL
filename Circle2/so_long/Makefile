.PHONY: 		clean fclean re

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wno-nonnull -g3

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/create_map/ft_fill_map.c \
      $(SRC_DIR)/create_map/ft_is_valid.c \
	  $(SRC_DIR)/create_map/ft_wall_valid.c \
	  $(SRC_DIR)/create_map/ft_objects_valid.c \
      $(SRC_DIR)/gnl/get_next_line.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[1;34mCompilation terminée avec succès ! 💕\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	@rm -f $(NAME)

re: fclean all
