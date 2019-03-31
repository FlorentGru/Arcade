##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_CORE			=	$(SRC_DIR_CORE)main.cpp	\
                        $(SRC_DIR_CORE)InitWindow.cpp	\
                        $(SRC_DIR_CORE)core.cpp	\
                        $(SRC_DIR_CORE)Menu/Menu.cpp	\
                        $(SRC_DIR_CORE)Menu/Rect.cpp	\
                        $(SRC_DIR_CORE)Menu/Score.cpp   \
                        $(SRC_DIR_CORE)InfoDisplay/CircleInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/LineInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/RectInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/SoundInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/TextInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/WindowInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/SpriteInfo.cpp	\
                        $(SRC_DIR_CORE)InfoDisplay/ADrawableInfo.cpp	\

NAME_CORE		=	arcade

OBJECTS_CORE 	= 	$(SRC_CORE:%.cpp=%.o)

SRC_DIR_CORE	=	./core/srcs/

INC_CORE		=	-I ./core/include/ -I ./core/include/InfoDisplay/ -I ./core/include/Menu/

CXXFLAGS 			=	-Wall -Wextra -W -Wshadow -fPIC $(INC_CORE)

CXX 			= 	g++

MAKE 			= 	make -C

all:		core game graphicals

core:		$(OBJECTS_CORE)
			$(CXX) -o $(NAME_CORE) $(OBJECTS_CORE) -ldl -lstdc++fs

game:
			make re -C games/

graphicals:
			make re -C lib/

clean:
			$(RM) $(OBJECTS_CORE)
			make clean -C games/
			make clean -C lib/

fclean: 	clean
			$(RM) $(NAME_CORE)
			make fclean -C games/
			make fclean -C lib/

re:			fclean all

debug: 		CXXFLAGS += -g
debug:		re
