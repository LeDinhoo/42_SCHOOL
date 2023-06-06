.PHONY: clean fclean re norm

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -ggdb

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT = $(addprefix $(LIBF_DIR), $(LIBFT_A))

PRINT_A = libftprintf.a
PRINT_DIR = ft_printf/
PRINT = $(addprefix $(PRINT_DIR), $(PRINT_A))

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/move/ft_swap.c \
	$(SRC_DIR)/move/ft_rotate.c \
	$(SRC_DIR)/move/ft_rev_rotate.c \
	$(SRC_DIR)/utils/ft_add.c \
	$(SRC_DIR)/utils/ft_push.c \
	$(SRC_DIR)/utils/ft_print_list.c \
	$(SRC_DIR)/utils/ft_create_list.c \
	$(SRC_DIR)/utils/ft_sort.c \
	$(SRC_DIR)/utils/ft_short_sort.c \
	$(SRC_DIR)/utils/ft_short_sort2.c \
	$(SRC_DIR)/utils/ft_check.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINT) norm
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): force
	@$(MAKE) -C $(LIBF_DIR)

$(PRINT): force
	@$(MAKE) -C $(PRINT_DIR)

force: ;

norm:
	@if ! norminette main.c ./libft ./move ./utils ./ft_printf | grep -v "OK" > /dev/null; then \
		echo "Norminette valide ! ✔️"; \
	else \
		norminette main.c ./libft ./move ./utils ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
	fi

clean:
	@echo "Suppression des fichiers objets...🗑"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBF_DIR) clean
	@$(MAKE) -C $(PRINT_DIR) clean

fclean: clean
	@echo "Suppression du programme final...🗑"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBF_DIR) fclean
	@$(MAKE) -C $(PRINT_DIR) fclean

re: fclean norm all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/move $(OBJ_DIR)/utils
