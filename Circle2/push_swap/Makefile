.PHONY: 		clean fclean re norm

NAME = push_swap

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

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

PRINT_A		= libftprintf.a
PRINT_DIR 	= ft_printf/
PRINT		= $(addprefix $(PRINT_DIR), $(PRINT_A))

SRC =	$(SRC_DIR)/main.c 					\
		$(SRC_DIR)/move/ft_swap.c 			\
		$(SRC_DIR)/move/ft_rotate.c 		\
		$(SRC_DIR)/move/ft_rev_rotate.c		\
		$(SRC_DIR)/utils/ft_add.c 			\
		$(SRC_DIR)/utils/ft_push.c 			\
		$(SRC_DIR)/utils/ft_print_list.c 	\
		$(SRC_DIR)/utils/ft_create_list.c 	\
		$(SRC_DIR)/utils/ft_sort.c 			\
		$(SRC_DIR)/utils/ft_short_sort.c 	\
		$(SRC_DIR)/utils/ft_check.c 		\


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) norm
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINT) -o $(NAME)
	@echo "\033[1;34mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/move $(OBJ_DIR)/utils
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@if ! norminette main.c ./libft ./move ./utils ./ft_printf | grep -v "OK" > /dev/null; then \
		echo "\033[1;32mNorminette valide ! ✔️\033[0m"; \
	else \
		norminette main.c ./libft ./move ./utils ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
	fi

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	@rm -f $(NAME)

re: fclean norm all
