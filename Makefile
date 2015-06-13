NAME = lem-in

SRC = lemin.c \
	 get_next_line.c \
	 parse.c \
	 misc.c \
	 stock.c \
	 algo.c \
	 ants.c \
	 game.c \
	 destroy.c \
	 search.c \

SRC_DIR = src

OBJ_DIR = objs

SRCS 		=   $(addprefix  $(SRC_DIR)/, $(notdir $(SRC)))

OBJ			=	$(addprefix  $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

INC			=	-Iinc -Ilibft
LINK		=	-L ./libft -lft

CFLAGS		=	-Wall -Wextra -Werror -g3 -g -pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments

FLAGS		=	$(CFLAGS)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f

all			: 	$(OBJ_DIR)	$(NAME)

$(NAME)		:	$(OBJ)
	@make -C ./libft
	$(CC) $(FLAGS) $(SRCS) $(INC) -o $(NAME) $(LINK)

$(OBJ):$(SRCS)
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean		:
	@make -C ./libft clean
	@$(RM) $(OBJ)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

fclean		:	clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re			:	fclean all

