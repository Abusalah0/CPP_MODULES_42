CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Bureaucrat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = Bureaucrat
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
