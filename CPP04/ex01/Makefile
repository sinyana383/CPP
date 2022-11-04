NAME 		= a.out

CC			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror
INCFLAGS 	= -MMD -I./inc

VPATH		= src/

SRCS		= main.cpp\
				Animal.cpp Cat.cpp Dog.cpp\
				WrongAnimal.cpp WrongCat.cpp\
				Brain.cpp

ODIR		= tmp
OBJS		= $(SRCS:%.cpp=$(ODIR)/%.o)

DDIR        = tmp
DEPS        = $(SRCS:%.cpp=$(DDIR)/%.d)

.PHONY:		all clean fclean re

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $@

$(ODIR)/%.o: %.cpp $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CC) $(CPPFLAGS) $(INCFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

all: $(NAME)

clean:
	rm -r -f $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEPS):
include $(wildcard $(DEPS))