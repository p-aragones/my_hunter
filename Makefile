##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	my_hunter

SRC		=	src/principal_functions/my_hunter.c			\
			src/principal_functions/init_hunt.c 		\
			src/principal_functions/game_setup.c 		\
			src/principal_functions/game_loop.c 		\
			src/support_functions/print_h.c 			\
			src/support_functions/print_score.c 		\
			src/support_functions/move_rect.c 			\
			src/support_functions/destroy_components.c	\
			src/support_functions/clock_manager.c 		\
			src/support_functions/score_manager.c 		\
			src/support_functions/help_flag.c 			\

OBJ	=	$(SRC:.c=.o)

CFLAGS		+=	-I./include/ -l csfml-graphics -l csfml-system -l csfml-audio -g3

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

run_tests:

re:		fclean all
		$(MAKE) re -C lib/my
