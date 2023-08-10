.PHONY: all clean fclean re

NAME = philo
CC = gcc
CFLAGS = 
INCLUDE_DIR = include
INCLUDES = -I$(INCLUDE_DIR) 

SRC_DIR = .
OBJ_DIR = .obj

SRC = 	$(SRC_DIR)/main.c \
	 	$(SRC_DIR)/srcs/utils.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@
	@echo "Compilation terminée avec succès ! ✔️"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
