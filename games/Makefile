##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_GAME1		=	$(SRC_DIR_GAME1)games.cpp	\

SRC_GAME2		=	$(SRC_DIR_GAME2)games.cpp	\

NAME_GAME1		=	lib_game1.so

NAME_GAME2		=	lib_game2.so

OBJECTS_GAME1 	= 	$(SRC_GAME1:%.cpp=%.o)

OBJECTS_GAME2 	= 	$(SRC_GAME2:%.cpp=%.o)

SRC_DIR_GAME1	=	./srcs/game1/

SRC_DIR_GAME2	=	./srcs/game2/

INC_GAME		=	-I ./include/

CXXFLAGS 			=	-Wall -Wextra -W -Wshadow -fPIC -lsfml-graphics -lsfml-window -lsfml-system -lncurses $(INC_GAME)

CXX 			= 	g++ -shared

MAKE 			= 	make -C

all:		game1 game2

game1:		$(OBJECTS_GAME1)
			$(CXX) -o $(NAME_GAME1) $(OBJECTS_GAME1)

game2:		$(OBJECTS_GAME2)
			$(CXX) -o $(NAME_GAME2) $(OBJECTS_GAME2)

clean:
			$(RM) $(OBJECTS_GAME1)
			$(RM) $(OBJECTS_GAME2)

fclean: 	clean
			$(RM) $(NAME_GAME1)
			$(RM) $(NAME_GAME2)

re:			fclean all

debug: 		CFLAGS += -g
debug:		re
