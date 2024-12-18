NAME		  :=	out 
CC			  :=	c++
FLAGS		  :=	-Wall -Wextra -Werror -std=c++17
SRC			  :=	main.cpp PmergeMe.cpp
OBJ			  :=	$(SRC:.cpp=.o)

# Colors
YELLOW		:= \033[38;2;204;204;0m
ORANGE		:= \033[38;2;255;87;34m
RESET		  := \033[0m

# Cursor manipulation
UP			  := \033[A
CUT			  := \033[K
BEGIN		  := \033[0G

all 		  : $(NAME)

$(NAME) 	: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o 		  : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean		  :
	@echo "$(UP)$(BEGIN)$(CUT)$(YELLOW)🧹Cleaning object files...$(RESET)"
	@rm -rf $(OBJ)

fclean		:
	@echo "$(UP)$(BEGIN)$(CUT)$(ORANGE)🔥Full clean, removing executable...$(RESET)"
	@rm -rf $(OBJ)
	@rm -f $(NAME)

re			  : fclean all

.PHONY 		: all clean fclean re