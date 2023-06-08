.PHONY: all clean fclean re

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = include
INCLUDES = -I$(INCLUDE_DIR)

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A = libft.a
LIBFT_DIR = utils/libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

PRINTF_A = libftprintf.a
PRINTF_DIR = utils/ft_printf/
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/utils/env_utils.c \
	$(SRC_DIR)/utils/cmd_utils2.c \
	$(SRC_DIR)/utils/cmd_utils.c \
	$(SRC_DIR)/utils/fd_utils.c \
	$(SRC_DIR)/utils/error_utils.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_SRC = $(wildcard $(LIBFT_DIR)*.c)
LIBFT_OBJ = $(LIBFT_SRC:$(LIBFT_DIR)%.c=$(LIBFT_DIR).objs/%.o)
LIBFT_DEPS = $(LIBFT_OBJ:.o=.d)

PRINTF_SRC = $(wildcard $(PRINTF_DIR)*.c)
PRINTF_OBJ = $(PRINTF_SRC:$(PRINTF_DIR)%.c=$(PRINTF_DIR).objs/%.o)
PRINTF_DEPS = $(PRINTF_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(PRINTF) -o $@
	@echo "Compilation terminée avec succès ! ✔️"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(LIBFT): $(LIBFT_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "Compilation de libft terminée ! ✔️"

$(PRINTF): $(PRINTF_OBJ)
	@$(MAKE) -C $(PRINTF_DIR) -s
	@echo "Compilation de ft_printf terminée ! ✔️"

$(LIBFT_DIR).objs/%.o: $(LIBFT_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(PRINTF_DIR).objs/%.o: $(PRINTF_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

force: ;

clean:
	@echo "Suppression des fichiers objets... 🗑️"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(MAKE) -C $(PRINTF_DIR) clean -s

fclean: clean
	@echo "Suppression du programme final... 🗑️"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@$(MAKE) -C $(PRINTF_DIR) fclean -s

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(LIBFT_DIR).objs
	@mkdir -p $(PRINTF_DIR).objs

-include $(LIBFT_DEPS) $(PRINTF_DEPS)
