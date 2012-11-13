##
## Makefile for  in /home/thomas_t//projet/p9_nibbler
## 
## Made by arnaud thomas-desessarts
## Login   <thomas_t@epitech.net>
## 
## Started on  Wed Mar  7 18:40:03 2012 arnaud thomas-desessarts
## Last update Sun Mar 18 22:08:55 2012 arnaud thomas-desessarts
##

## DIRECTORIES
CORE		=	core/
ERRORS		=	errors/
LIB_SDL		=	libs/SDL/
LIB_OPENGL	=	libs/OpenGL/
LIB_NCURSES	=	libs/Ncurses/

## COMPILATION & ALIAS
CXXFLAGS	+=	-Wall -Wextra -g
CXX		=	g++
RM		=	rm -f

## CORE
NAME_CORE	=	nibbler
NAME_SDL	=	sdl
NAME_OPENGL	=	opengl
NAME_NCURSES	=	ncurses
SRC_CORE	=	$(CORE)main.cpp			\
			$(ERRORS)stringToInt.cpp	\
			$(ERRORS)checkUsage.cpp		\
			$(ERRORS)checkMap.cpp		\
			$(CORE)getError.cpp		\
			$(CORE)initCore.cpp		\
			$(CORE)runGame.cpp		\
			$(CORE)switchLib.cpp		\
			$(CORE)Core.cpp			\
			$(CORE)getAvailableLibs.cpp	\
			$(CORE)getAPIDatas.cpp		\
			$(CORE)printMap.cpp		\
			$(CORE)growQueue.cpp		\
			$(CORE)initCoordinates.cpp	\
			$(CORE)putApple.cpp		\
			$(CORE)pressEscape.cpp		\
			$(CORE)moveUp.cpp		\
			$(CORE)moveDown.cpp		\
			$(CORE)moveLeft.cpp		\
			$(CORE)moveRight.cpp		\
			$(CORE)moveSnake.cpp		\
			$(CORE)extractHighScores.cpp	\
			$(CORE)generateMap.cpp		\
			$(CORE)actionOnKeydown.cpp	\
			$(CORE)saveScore.cpp
OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

all		:	$(NAME_SDL) $(NAME_NCURSES) $(NAME_OPENGL) $(NAME_CORE)
## MAKE : CORE
$(NAME_CORE)	:	$(OBJ_CORE)
			@printf "\033[0;32m[Completed] Core compilation\033[m\n"
			$(CXX) $(OBJ_CORE) -L. -lSDL -lSDL_ttf -lSDL_image -ldl -o $(NAME_CORE)
## MAKE : LIB - SDL
$(NAME_SDL)	:
			@cd $(LIB_SDL) ; make ; cd -
			@cp $(LIB_SDL)libSDL.so .
## MAKE : LIB - NCURSES
$(NAME_NCURSES)	:
			@cd $(LIB_NCURSES) ; make ; cd -
			@cp $(LIB_NCURSES)libNcurses.so .
## MAKE : LIB - OPENGL
$(NAME_OPENGL)	:
			@cd $(LIB_OPENGL) ; make ; cd -
			@cp $(LIB_OPENGL)libOpenGL.so .
clean		:	cleanCore cleanSDL cleanNcurses cleanOpenGL
cleanCore	:
			$(RM) $(OBJ_CORE)
cleanSDL	:
			@cd $(LIB_SDL) ; make clean ; cd -
cleanNcurses	:
			@cd $(LIB_NCURSES) ; make clean ; cd -
cleanOpenGL	:
			@cd $(LIB_OPENGL) ; make clean ; cd -
fclean		:	fcleanCore fcleanSDL fcleanNcurses fcleanOpenGL
fcleanCore	:	cleanCore
			$(RM) $(NAME_CORE)
fcleanSDL	:
			@cd $(LIB_SDL) ; make fclean ; cd -
fcleanNcurses	:
			@cd $(LIB_NCURSES) ; make fclean ; cd -
fcleanOpenGL	:
			@cd $(LIB_OPENGL) ; make fclean ; cd -
re		:	reSDL reNcurses reOpenGL reCore
reCore		:	fcleanCore $(NAME_CORE)
reSDL		:	
			@cd $(LIB_SDL) ; make re ; cd -
			@cp $(LIB_SDL)libSDL.so .
reNcurses	:	
			@cd $(LIB_NCURSES) ; make re ; cd -
			@cp $(LIB_NCURSES)libNcurses.so .
reOpenGL	:	
			@cd $(LIB_OPENGL) ; make re ; cd -
			@cp $(LIB_OPENGL)libOpenGL.so .

.PHONY		:	all clean fclean re
