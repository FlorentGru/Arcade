##
## EPITECH PROJECT, 2019
## cpp_d06_2018
## File description:
## Makefile
##

SRC_CORE			=	$(SRC_DIR_CORE)core.cpp	\

NAME_CORE		=	arcade

OBJECTS_CORE 	= 	$(SRC_CORE:%.cpp=%.o)

SRC_DIR_CORE	=	./core/srcs/

INC_CORE		=	-I ./core/include/

CXXFLAGS 			=	-Wall -Wextra -W -Wshadow  $(INC_CORE)

CXX 			= 	g++

MAKE 			= 	make -C

all:		core game graphicals

core:		$(OBJECTS_CORE)
			$(CXX) -o $(NAME_CORE) $(OBJECTS_CORE)

game:
			$(MAKE) games/

graphicals:
			$(MAKE) lib/

clean:
			$(RM) $(OBJECTS_CORE)
			make clean -C games/
			make clean -C lib/

fclean: 	clean
			$(RM) $(NAME_CORE)
			make fclean -C games/
			make fclean -C lib/

re:			fclean all

debug: 		CFLAGS += -g
debug:		re
