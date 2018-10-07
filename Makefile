NAME	= ft_retro

SRC 	= Bullet.cpp Enemy.cpp main.cpp Object.cpp Point.cpp Ship.cpp

OBJ		= $(SRC:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

HEADER	= Bullet.hpp Enemy.hpp Object.hpp Point.hpp Ship.hpp

LIB = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@ clang++ $(FLAGS) $(LIB) -o $(NAME) $(OBJ)

%.o: %.cpp
	@ clang++ $(FLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all