##
## EPITECH PROJECT, 2021
## makefile
## File description:
## generate binary
##

SRC	=	src/main.c	\
		src/connect_player.c	\
		src/signal_handler.c	\
		src/game_handler.c	\
		src/error/error_handler.c	\
		src/boat_gestion.c \
		src/map_handler.c \
		src/map_utils.c \
		src/attack_handler.c \
		src/display_result.c \

OBJ	=	$(SRC:.c=.o)

TEST =	src/connect_player.c	\

NAME	=	navy

CPPFLAGS	=	-I./include

LIB     =       -L lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*
	rm -f unit_tests

fclean : clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LIB) -ggdb3

tests_run:
	make -C lib/my
	gcc -o unit_tests $(TEST) $(CPPFLAGS) -Llib/ -lmy -lcriterion --coverage
	./unit_tests
