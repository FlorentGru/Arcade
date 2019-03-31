##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_GAME1		=	$(SRC_DIR_GAME1)pacman_setter_getter.cpp	\
					$(SRC_DIR_GAME1)pacman.cpp	\
					$(SRC_DIR_GAME1)Ghost.cpp	\
					../core/srcs/InfoDisplay/CircleInfo.cpp	\
					../core/srcs/InfoDisplay/LineInfo.cpp	\
					../core/srcs/InfoDisplay/SoundInfo.cpp	\
					../core/srcs/InfoDisplay/RectInfo.cpp	\
					../core/srcs/InfoDisplay/TextInfo.cpp	\
					../core/srcs/InfoDisplay/WindowInfo.cpp	\
					../core/srcs/InfoDisplay/SpriteInfo.cpp	\
					../core/srcs/InfoDisplay/ADrawableInfo.cpp	\
					../core/srcs/InitWindow.cpp			\

SRC_GAME2		=	$(SRC_DIR_GAME2)snake.cpp	\
					$(SRC_DIR_GAME2)nibbler.cpp	\
					$(SRC_DIR_GAME2)food.cpp	\
					../core/srcs/InfoDisplay/CircleInfo.cpp	\
					../core/srcs/InfoDisplay/LineInfo.cpp	\
					../core/srcs/InfoDisplay/SoundInfo.cpp	\
					../core/srcs/InfoDisplay/RectInfo.cpp	\
					../core/srcs/InfoDisplay/TextInfo.cpp	\
					../core/srcs/InfoDisplay/WindowInfo.cpp	\
					../core/srcs/InfoDisplay/SpriteInfo.cpp	\
					../core/srcs/InfoDisplay/ADrawableInfo.cpp	\
					../core/srcs/InitWindow.cpp			\

NAME_GAME1		=	lib_arcade_pacman.so

NAME_GAME2		=	lib_arcade_nibbler.so

OBJECTS_GAME1 	= 	$(SRC_GAME1:%.cpp=%.o)

OBJECTS_GAME2 	= 	$(SRC_GAME2:%.cpp=%.o)

SRC_DIR_GAME1	=	./srcs/pacman/

SRC_DIR_GAME2	=	./srcs/Nibbler/

INC_GAME		=	-I ./include/ -I ./../core/include/ -I ./../core/include/InfoDisplay/

CXXFLAGS 			=	-Wall -Wextra -W -Wshadow -fPIC -lsfml-graphics -lsfml-window -lsfml-system -lncurses $(INC_GAME)

CXX 			= 	g++ -shared

MAKE 			= 	make -C

all:		clean game2 game1

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
