##
## EPITECH PROJECT, 2024
## delivery
## File description:
## Makefile
##

NAME	:=	my_rpg

SRC_DIR :=	src

PLAYER_DIR := src/player

MENU_DIR := src/menu_gestion

MENU_INIT_DIR := src/menu_gestion/initialisation

ENNEMY_DIR := src/ennemy

PNJ_DIR := src/pnj

INIT_ENT := src/init_entities

CHEST_DIR := src/chest

MAIN_MENU_DIR := src/main_menu

MOUV_DIR := src/mouvement

INV_DIR := src/inventaire

SRC	:=	$(wildcard $(SRC_DIR)/*.c)	\
		$(wildcard $(ENNEMY_DIR)/*.c)	\
		$(wildcard $(PNJ_DIR)/*.c)	\
		$(wildcard $(CHEST_DIR)/*.c)	\
		$(wildcard $(PLAYER_DIR)/*.c)\
		$(wildcard $(MOUV_DIR)/*.c)\
		$(wildcard $(INV_DIR)/*.c)\
		$(wildcard $(MENU_DIR)/*.c)\
		$(wildcard $(MENU_INIT_DIR)/*.c)\
		$(wildcard $(MAIN_MENU_DIR)/*.c)\
		$(wildcard $(INIT_ENT)/*.c)\

OBJ	:= $(SRC:.c=.o)

LDFLAGS := -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm


CPPFLAGS	:=	-Iinclude -Llib -lmy -lcsfml_tool

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/csfml_tool
	$(CC) -o $(NAME) $(OBJ)  ${LDFLAGS} ${CPPFLAGS}

all: $(NAME)

clean:
	make clean -C lib/my
	make clean -C lib/csfml_tool
	rm -f *~
	rm -f #*#
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	make fclean -C lib/csfml_tool
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
