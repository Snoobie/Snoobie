##
## Makefile<2> for  in /home/thomas_t//projet/p9_nibbler/libs/SDL
## 
## Made by arnaud thomas-desessarts
## Login   <thomas_t@epitech.net>
## 
## Started on  Fri Mar  9 12:14:10 2012 arnaud thomas-desessarts
## Last update Sun Mar 18 22:09:37 2012 arnaud thomas-desessarts
##

NAME		=	libSDL.so
SRC		=	SDL.cpp
OBJ		=	$(SRC:.cpp=.o)
LDFLAGS		+=	-lSDL -lSDL_ttf -lSDL_image
CXXFLAGS	+=	-Wall -Wextra -fPIC
CXX		=	g++
RM		=	rm -f

$(NAME)		:	$(OBJ)
			@printf "\033[0;32m[Completed] SDL compilation\033[m\n"
			$(CXX) -o $(NAME) -shared $(OBJ) $(LDFLAGS)
all		:	$(NAME)
clean		:
			$(RM) $(OBJ)
fclean		:	clean
			$(RM) ../../$(NAME)
re		:	fclean all

.PHONY		:	all clean fclean re