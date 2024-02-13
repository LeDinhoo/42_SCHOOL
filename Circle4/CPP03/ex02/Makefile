.PHONY: all clean fclean re

NAME = ClapTrap
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .obj

SRC = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/ClapTrap.cpp \
		$(SRC_DIR)/ScavTrap.cpp \
		$(SRC_DIR)/FragTrap.cpp \


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@