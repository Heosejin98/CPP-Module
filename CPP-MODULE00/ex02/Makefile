NAME	= Account
	
CC		= clang++
FLAGS	= -std=c++98
RM		= rm -rf

.PHONY: all clean re

all: $(NAME)

$(NAME): 
	@ $(CC) $(FLAGS) tests.cpp Account.cpp -o $(NAME)


clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: clean all