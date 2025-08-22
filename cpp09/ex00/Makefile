NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCDIR = .
SOURCES = main.cpp BitcoinExchange.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
