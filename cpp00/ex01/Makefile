# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 14:13:08 by nrontey           #+#    #+#              #
#    Updated: 2024/12/20 14:13:08 by nrontey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Phonebook

src = main.cpp \
	Phonebook.cpp \
	Contact.cpp

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