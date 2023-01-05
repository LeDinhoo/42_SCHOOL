
.PHONY: all clean fclean re

#Name
NAME = so_long.out

#Compilation Flags
CFLAGS = -Wall -Wextra -Werror -g3

#Directories
HEADERS		= 	so_long.h \

MAIN		= 	main.c \

GNL			= 	get_next_line_utils.c \
				get_next_line.c \

CMAP		= 	ft_fill_map.c \
				ft_is_valid.c \

MAPS		= 	test.ber \

DIR_OBJS = .objs/
OBJS = $(addprefix $(DIR_OBJS), $(SRC:.c=.o))

#Sources
SRC			= $(SRC_CMAP) $(SRC_GNL) $(SRC_MAPS) $(MAIN)
SRC_H		= $(addprefix headers/, $(HEADERS))
SRC_GNL		= $(addprefix gnl/, $(GNL))
SRC_CMAP	= $(addprefix create_map/, $(CMAP))
SRC_MAPS	= $(addprefix maps/, $(MAPS))

RM = rm -rf

all: $(NAME)

$(NAME): 		$(DIR_OBJS) $(OBJS) $(SRC_H) Makefile
				gcc $(NAME) $(OBJS)

$(DIR_OBJS):
				mkdir -p $(DIR_OBJS)

$(DIR_OBJS)%.o: %.c $(SRC_H) Makefile
				gcc $(CFLAGS) -c $< -o $@ -I $(SRC_H)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(DIR_OBJS)

re: fclean all
