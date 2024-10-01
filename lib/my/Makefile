##
## EPITECH PROJECT, 2023
## make file
## File description:
## ..
##
SRC	:=	my_getnbr.c	\
		my_strlen.c	\
		my_putchar.c	\
		my_strdup.c	\
		my_strcpy.c	\
		my_strcmp.c	\
		how_many_digits.c 	\
		my_abs.c	\
		my_str_to_word_array.c	\
		input.c	\
		my_putstr.c	\
		my_arraylen.c	\
		my_strncpy.c	\
		my_strncmp.c	\
		my_strcat.c	\
		my_show_word_array.c\
		my_revstr.c\

OBJ	=	$(SRC:.c=.o)

NAME    =       libmy.a

all:	$(NAME)

libmy.a: $(NAME)

$(NAME): $(OBJ)
	cp my.h ../../include/my.h
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
re: fclean all


PHONY: all re fclean clean libmy.a
