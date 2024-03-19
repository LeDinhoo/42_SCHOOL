.PHONY: all clean fclean re

NAME = ScalarConverter
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .obj
INCLUDE = -I./include

SRC = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/ScalarConverter.cpp \


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@%       