##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/brain.c		\
		srcs/init.c		\
		srcs/events.c		\
		srcs/map.c		\
		srcs/displayer.c	\
		srcs/zombie.c		\
		srcs/menu.c		\
		srcs/init_textures.c	\

OBJ	=	$(SRC:.c = .o)

NAME	=	my_runner

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc

C_FLAGS	=	-Wall -Wextra

LIB_FLAG	=	-l c_graph_prog

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(C_FLAGS) -L./lib $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
