##
## EPITECH PROJECT, 2023
## my_sokoban
## File description:
## Infos
##

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_putstr.c 	\
			lib/my_printf.c		\
			lib/my_strcmp.c 	\
			lib/my_strlen.c 	\
			lib/my_strcpy.c 	\
			lib/my_putchar.c	\
			lib/my_put_nbr.c 	\
			lib/my_put_nbr_recursive.c	\

SRCNAME	=	main.c		\
			in_game.c 	\
			in_game_key.c	\


LIB = libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)
OBJNAME	=	$(SRCNAME:.c=.o)

NAME	=	my_sokoban

$(NAME) : $(LIB) $(OBJNAME)
	gcc -lncurses -o $(NAME) $(OBJNAME) -lmy -L./ -g3

$(LIB) : $(OBJLIB)
	ar rc libmy.a lib/*.o


all:	$(LIB) $(NAME)

clean:
	rm -f $(OBJLIB) $(OBJNAME) libmy.a

fclean: clean
	rm -f $(NAME)

re: 	fclean all
