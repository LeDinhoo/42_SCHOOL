.PHONY: all clean fclean re

NAME = megaphone
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .obj

SRC = 	$(SRC_DIR)/ex00.cpp \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "Compilation terminée avec succès ! ✔️"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@echo "Suppression des fichiers objets... 🗑️"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Suppression du programme final... 🗑️"
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/srcs
