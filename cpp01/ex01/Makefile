# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 23:33:55 by nrontey           #+#    #+#              #
#    Updated: 2025/01/06 12:30:52 by nrontey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ZombieHorde

src = main.cpp Zombie.cpp zombieHorde.cpp

obj = $(src:.cpp=.o)

all: $(NAME)

$(NAME): $(obj)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(obj)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
