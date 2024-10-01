##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile
##

SRC	:=	src/main.c \
		src/my_str_to_word_array.c\



OBJ	:=	${SRC:.c=.o}

NAME := txt_to_map

CFLAGS	:= 	-g3


CPPFLAGS	:=	-Iinclude 

all: ${NAME}

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJ}
	rm -f vgcore.*
	rm -f *.log

re: fclean
	${MAKE} all

${NAME}: ${OBJ}

	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -g3

.PHONY: all re fclean clean
