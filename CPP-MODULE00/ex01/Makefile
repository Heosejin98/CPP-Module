NAME	= PhoneBook
	
CC		= clang++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: all clean re

all: $(NAME)

$(NAME): 
	@ $(CC) $(FLAGS) main.cpp PhoneBook.cpp Contact.cpp -o $(NAME)


clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: clean all