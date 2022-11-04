NAME 		= a.out

CC			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS		= main.cpp\
				ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

HEADERS		= ClapTrap.h ScavTrap.h FragTrap.h

ODIR		= tmp
OBJS		= $(SRCS:%.cpp=$(ODIR)/%.o)

.PHONY:		all clean fclean re

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $@

$(ODIR)/%.o: %.cpp $(HEADERS) | $(ODIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

all: $(NAME)

clean:
	rm -r -f $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
