NAME	:=	push_swap

CSAN	:=	-fsanitize=address -g3

CC	:=	gcc
CFLAGS	:= -Wall -Wextra -Werror #$(CSAN)

DIR_SRCS	:=	sources
DIR_OBJS	:=	.objs
DIR_INCS	:=	includes

LST_SRCS	:=	main.c \
				parsing.c \
				utils.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	push_swap.h

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $< -o $@

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
					$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@

$(DIR_OBJS)	:
				mkdir -p $(DIR_OBJS)

clean	:
			rm -rf $(OBJS)

fclean	:
			clean
			rm -rf $(NAME)

re	:
		fclean
		all

.PHONY	:	all clean fclean re