##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_LIB1		=	$(SRC_DIR_LIB1)sfmlDisplayModule.cpp	\
                    ../core/srcs/InfoDisplay/CircleInfo.cpp	\
                    ../core/srcs/InfoDisplay/LineInfo.cpp	\
                    ../core/srcs/InfoDisplay/RectInfo.cpp	\
                    ../core/srcs/InfoDisplay/SoundInfo.cpp	\
                    ../core/srcs/InfoDisplay/TextInfo.cpp	\
                    ../core/srcs/InfoDisplay/WindowInfo.cpp	\
                    ../core/srcs/InfoDisplay/SpriteInfo.cpp	\
                    ../core/srcs/InfoDisplay/ADrawableInfo.cpp	\
                    ../core/srcs/InitWindow.cpp


SRC_LIB2		=	$(SRC_DIR_LIB2)ncursesDisplayModule.cpp\
                    ../core/srcs/InfoDisplay/CircleInfo.cpp	\
                    ../core/srcs/InfoDisplay/LineInfo.cpp	\
                    ../core/srcs/InfoDisplay/SoundInfo.cpp	\
                    ../core/srcs/InfoDisplay/RectInfo.cpp	\
                    ../core/srcs/InfoDisplay/TextInfo.cpp	\
                    ../core/srcs/InfoDisplay/WindowInfo.cpp	\
                    ../core/srcs/InfoDisplay/SpriteInfo.cpp	\
                    ../core/srcs/InfoDisplay/ADrawableInfo.cpp	\
                    ../core/srcs/InitWindow.cpp			\

SRC_LIB3		=	$(SRC_DIR_LIB3)allegroDisplayModule.cpp	\
                    ../core/srcs/InfoDisplay/CircleInfo.cpp	\
                    ../core/srcs/InfoDisplay/LineInfo.cpp	\
                    ../core/srcs/InfoDisplay/RectInfo.cpp	\
                    ../core/srcs/InfoDisplay/SoundInfo.cpp	\
                    ../core/srcs/InfoDisplay/TextInfo.cpp	\
                    ../core/srcs/InfoDisplay/WindowInfo.cpp	\
                    ../core/srcs/InfoDisplay/SpriteInfo.cpp	\
                    ../core/srcs/InfoDisplay/ADrawableInfo.cpp	\
                    ../core/srcs/InitWindow.cpp			\

NAME_LIB1		=	lib_arcade_SFML.so

NAME_LIB2		=	lib_arcade_ncurses.so

NAME_LIB3		=	lib_arcade_allegro.so

OBJECTS_LIB1 	= 	$(SRC_LIB1:%.cpp=%.o)

OBJECTS_LIB2 	= 	$(SRC_LIB2:%.cpp=%.o)

OBJECTS_LIB3 	= 	$(SRC_LIB3:%.cpp=%.o)

SRC_DIR_LIB1	=	./srcs/SFML/

SRC_DIR_LIB2	=	./srcs/ncurses/

SRC_DIR_LIB3	=	./srcs/allegro/

INC_LIB		=	-I ./include/SFML/ -I ./../core/include/ -I ./../core/include/InfoDisplay/ -I ./include/allegro/ -I ./include/ncurses/

CXXFLAGS 		=	-Wall -Wextra -W -Wshadow -fPIC $(INC_LIB)

SFML			=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

NCURSES			=	-lncurses

ALLEGRO			=	-L/usr/lib64 -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf  -lallegro_image -lallegro_dialog -lallegro_acodec -lallegro_audio -lallegro_color -lallegro_memfile -lallegro_physfs

CXX 			= 	g++ -shared

MAKE 			= 	make -C

all:		lib1 lib3 lib2

lib1:		$(OBJECTS_LIB1)
			$(CXX) -o $(NAME_LIB1) $(OBJECTS_LIB1)	$(SFML)

lib2:		$(OBJECTS_LIB2)
			$(CXX) -o $(NAME_LIB2) $(OBJECTS_LIB2)	$(NCURSES)

lib3:		$(OBJECTS_LIB3)
			$(CXX) -o $(NAME_LIB3) $(OBJECTS_LIB3) $(ALLEGRO)

clean:
			$(RM) $(OBJECTS_LIB1)
##			$(RM) $(OBJECTS_LIB2)
			$(RM) $(OBJECTS_LIB3)

fclean: 	clean
			$(RM) $(NAME_LIB1)
			$(RM) $(NAME_LIB2)
			$(RM) $(NAME_LIB3)

re:			fclean all

debug: 		CFLAGS += -g
debug:		re
