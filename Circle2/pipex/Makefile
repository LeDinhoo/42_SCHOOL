.PHONY: 		clean fclean re norm

NAME = pipex

CC = gcc

ifeq ($(shell uname),Linux)
   # Linux-specific commands
	MLXFLAGS =
	CFLAGS = -Wall -Wextra -Werror -ggdb
else
   # Mac OS X-specific commands
	CFLAGS = -Wall -Wextra -Werror
	MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm
endif

SRC_DIR = .
OBJ_DIR = .obj

LIBF_A		= libft.a
LIBF_DIR 	= utils/libft/
LIBF		= $(addprefix $(LIBF_DIR), $(LIBF_A))

PRINT_A		= libftprintf.a
PRINT_DIR 	= utils/ft_printf/
PRINT		= $(addprefix $(PRINT_DIR), $(PRINT_A))

SRC =	$(SRC_DIR)/main.c 					\
		$(SRC_DIR)/utils/get_env.c 					\

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME) $(LIBF)

$(NAME): $(OBJ) norm
	@$(CC) $(CFLAGS) $(OBJ) $(LIBF) $(PRINT) -o $(NAME)
	@echo "\033[1;95mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/move $(OBJ_DIR)/utils
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBF): $(LIBF_OBJ)/%.o
	$(CC) $(CFLAGS) $(LIBF_OBJ) $(LIBF) $(PRINT) -o $(LIBF_TARGET)
	@echo "\033[1;92mLibft recompilé avec succès ! ✔️\033[0m"

$(LIBF_OBJ): $(LIBF_DIR)/%.o
	$(CC) $(CFLAGS) $< -o $@

norm:
	@if ! norminette main.c ./utils/libft ./utils/ft_printf | grep -v "OK" > /dev/null; then \
		echo "\033[1;92mNorminette valide ! ✔️\033[0m" \
	else \
		norminette main.c ./libft ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
	fi

clean:
	@echo "\033[1;93mSuppression des fichiers objets... \033[0m����"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;93mSuppression du programme final... \033[0m����"
	@rm -f $(NAME)

re: fclean norm all