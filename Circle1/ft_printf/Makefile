

.PHONY: 		clean fclean re bonus

NAME 			= libftprintf.a
CFLAGS 			= -Wall -Wextra -Werror

LIST_HEADERS 	= ft_printf.h

SRCS 			=	ft_printf.c				\
					ft_printf_utils.c		\
					ft_printf_utils2.c		\

SRCS_B =


DIR_HEADERS 	= ./
DIR_OBJS 		= .objs/
RM				= rm -rf

# ---------------------------------------------------

OBJS 			= $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
OBJS_B 			= $(addprefix $(DIR_OBJS), $(SRCS_B:.c=.o))

all : 			$(NAME) $(BONUS)

$(NAME):		$(DIR_OBJS) $(OBJS) $(LIST_HEADERS) Makefile
				$(AR) rcs $(NAME) $(OBJS)

$(DIR_OBJS):
				mkdir -p $(DIR_OBJS)

bonus: 			$(DIR_OBJS) $(OBJS_B) $(OBJS) $(LIST_HEADERS) Makefile
				$(AR) rcs $(NAME) $(OBJS_B) $(OBJS)

$(DIR_OBJS)%.o: %.c $(LIST_HEADERS) Makefile
				$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

# ----------------------------------------------------- #

clean:
				$(RM) $(OBJS) $(OBJS_B)

fclean: clean
				$(RM) $(NAME)

re: fclean
				$(MAKE) all

