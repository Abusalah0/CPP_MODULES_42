CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
		truncate.cpp \
		check_input.cpp \
		Contact.cpp \
		PhoneBook.cpp
		
OBJS = $(SRCS:.cpp=.o)

NAME = NumbersYouWontAnswer
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
