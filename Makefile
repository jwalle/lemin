NAME = lem-in

SRC = src/lemin.c \
	 src/get_next_line.c \
	 src/parse.c \
	 src/misc.c \
	 src/stock.c \


OBJ			=	$(SRC:.c=.o)

INC			=	-I./inc -I./libft/includes
LINK		=	-Llibft -lft

CFLAGS		=	-Wall -Wextra -Werror -g3 -g -pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments

FLAGS		=	$(CFLAGS)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	@make -C ./libft
	@$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)

clean		:
	@make -C ./libft clean
	@$(RM) $(OBJ)

fclean		:	clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
