NAME	=	test

OBJ_DIR	=	.obj

SRCS	=	main.cpp Bureaucrat.cpp

CFLAGS	=	-std=c++98 -fsanitize=undefined -fsanitize=address -Wall -Werror -Wpedantic -Wextra -g

OBJ		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CC		=	c++

RM		=	rm -rf

HEADER	=	Bureaucrat.hpp	

$(OBJ_DIR)/%.o:%.cpp $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean	:
	@$(RM) $(OBJ_DIR)

fclean	:	clean
	@$(RM) $(NAME)

re		: fclean all
