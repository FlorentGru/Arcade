##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

ARCADE =		arcade

CORE =			core

GAMES =			games

GRAPHICALS =	graphicals

CXXCORE =		./Core/main.cpp

CXXGAMES =		./Games/main.cpp

CXXGRAPH =		./Graphicals/main.cpp

OBJCORE	=		$(CXXCORE:.cpp=.o)

OBJGAMES =		$(CXXGAMES:.cpp=.o)

OBJGRAPH =		$(CXXGRAPH:.cpp=.o)

CXX	=	g++

RM	=	rm -f

ECHO	=	@echo -e

INC	=	-I ./includes

CFLAGS	=	-W -Wall -Wextra -Werror

all:		$(ARCADE)

core:		$(CORE)

games:		$(GAMES)

graphicals:	$(GRAPHICALS)

$(ARCADE):		$(OBJCORE)
				$(CXX) $(OBJCORE) -o $(ARCADE) $(CFLAGS)
				$(ECHO) "\e[1;32m\n>>> Compilation Completed !<<<\e[0m"

$(CORE):		$(OBJCORE)
				$(CXX) $(OBJCORE) -o $(CORE) $(CFLAGS)
				$(ECHO) "\e[1;32m\n>>> Compilation Completed !<<<\e[0m"

$(GAMES):		$(OBJGAMES)
				$(CXX) -o $(GAMES) $(OBJGAMES) $(CFLAGS)
				$(ECHO) "\e[1;32m\n>>> Compilation Completed !<<<\e[0m"

$(GRAPHICALS):	$(OBJGRAPH)
				$(CXX) -o $(GRAPHICALS) $(OBJGRAPH) $(CFLAGS)
				$(ECHO) "\e[1;32m\n>>> Compilation Completed !<<<\e[0m"

clean:
		rm -f $(OBJCORE) *~ *#
		rm -f $(OBJGAMES) *~ *#
		rm -f $(OBJGRAPH) *~ *#

fclean:		clean
		$(RM) $(CORE) $(GAMES) $(GRAPHICALS) $(ARCADE) *~ *#

re:		fclean all
