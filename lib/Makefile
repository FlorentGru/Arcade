##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_LIB1		=	$(SRC_DIR_LIB1)lib.cpp	\

SRC_LIB2		=	$(SRC_DIR_LIB2)lib.cpp	\

SRC_LIB3		=	$(SRC_DIR_LIB3)lib.cpp	\

NAME_LIB1		=	lib_graph1.so

NAME_LIB2		=	lib_graph2.so

NAME_LIB3		=	lib_graph3.so

OBJECTS_LIB1 	= 	$(SRC_LIB1:%.cpp=%.o)

OBJECTS_LIB2 	= 	$(SRC_LIB2:%.cpp=%.o)

OBJECTS_LIB3 	= 	$(SRC_LIB3:%.cpp=%.o)

SRC_DIR_LIB1	=	./srcs/SFML/

SRC_DIR_LIB2	=	./srcs/ncurses/

SRC_DIR_LIB3	=	./srcs/other/

INC_GAME		=	-I ./include/

CXXFLAGS 			=	-Wall -Wextra -W -Wshadow -fPIC $(INC_GAME)

SFML			=	-lsfml-graphics -lsfml-window -lsfml-system

NCURSES			=	-lncurses

OTHER			=

CXX 			= 	g++ -shared

MAKE 			= 	make -C

all:		lib1 lib2 lib3

lib1:		$(OBJECTS_LIB1)
			$(CXX) -o $(NAME_LIB1) $(OBJECTS_LIB1)	$(SFML)

lib2:		$(OBJECTS_LIB2)
			$(CXX) -o $(NAME_LIB2) $(OBJECTS_LIB2)	$(NCURSES)

lib3:		$(OBJECTS_LIB3)
			$(CXX) -o $(NAME_LIB3) $(OBJECTS_LIB3) $(OTHER)

clean:
			$(RM) $(OBJECTS_LIB1)
			$(RM) $(OBJECTS_LIB2)
			$(RM) $(OBJECTS_LIB3)

fclean: 	clean
			$(RM) $(NAME_LIB1)
			$(RM) $(NAME_LIB2)
			$(RM) $(NAME_LIB3)

re:			fclean all

debug: 		CFLAGS += -g
debug:		re