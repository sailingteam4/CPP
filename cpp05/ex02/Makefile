NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp \
          Bureaucrat.cpp \
          AForm.cpp \
          ShrubberyCreationForm.cpp \
          RobotomyRequestForm.cpp \
          PresidentialPardonForm.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

HEADERS = Bureaucrat.hpp \
          AForm.hpp \
          ShrubberyCreationForm.hpp \
          RobotomyRequestForm.hpp \
          PresidentialPardonForm.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
