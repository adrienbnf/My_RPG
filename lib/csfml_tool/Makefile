##
## EPITECH PROJECT, 2023
## make file
## File description:
## ..
##

SRC	:=	create_rectangle.c 	\
		rect_are_colliding.c\

OBJ	:=	$(SRC:.c=.o)

NAME    :=       libcsfml_tool.a

LDFLAGS :=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

all:	$(NAME)

libmy.a: $(NAME)

$(NAME): $(OBJ)
	cp csfml_tool.h ../../include/csfml_tool.h
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
re: fclean all


PHONY: all re fclean clean libmy.a
