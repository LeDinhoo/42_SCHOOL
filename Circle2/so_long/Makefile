
NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-nonnull -g3

SRC_DIR = .
OBJ_DIR = .obj

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/create_map/ft_fill_map.c \
      $(SRC_DIR)/create_map/ft_is_valid.c \
      $(SRC_DIR)/gnl/get_next_line_utils.c \
      $(SRC_DIR)/gnl/get_next_line.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

