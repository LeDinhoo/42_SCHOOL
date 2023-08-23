.PHONY: all clean fclean re

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include

SRC_DIR = .
OBJ_DIR = .obj

SRC = 	$(SRC_DIR)/main.c \
	 	$(SRC_DIR)/srcs/utils.c \
	 	$(SRC_DIR)/srcs/error.c \
	 	$(SRC_DIR)/srcs/init.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lpthread -o $@
	@echo "Compilation terminée avec succès ! ✔️"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

force: ;

clean:
	@echo "Suppression des fichiers objets... 🗑️"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Suppression du programme final... 🗑️"
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/srcs/
