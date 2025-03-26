CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = Zombies
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
