NAME 		= harlFilter

CC			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS		= main.cpp\
				Harl.cpp

ODIR		= tmp
OBJS		= $(SRCS:%.cpp=$(ODIR)/%.o)

.PHONY:		all clean fclean re

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $@

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

all: $(NAME)

clean:
	rm -r -f $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
