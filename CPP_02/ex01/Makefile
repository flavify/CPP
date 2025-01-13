# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 13:34:21 by fvoicu            #+#    #+#              #
#    Updated: 2024/05/13 16:32:01 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	out
CC			:=	c++
FLAGS		:=	-Wall -Wextra -Werror -std=c++98
SRC			:=	main.cpp Fixed.cpp
OBJ			:=	$(SRC:.cpp=.o)

# Colors
YELLOW	:= \033[38;2;204;204;0m
ORANGE	:= \033[38;2;255;87;34m
RESET		:= \033[0m

# Cursor manipulation
UP			:= \033[A
CUT			:= \033[K
BEGIN		:= \033[0G

all 		: $(NAME)

$(NAME) : $(OBJ)
	@python3 anim.py &
	@ANIMATION_PID=$$!;
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@sleep 2
	@touch stop_animation.txt
	@wait $$ANIMATION_PID 2>/dev/null

%.o 		: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean		:
	@echo "$(UP)$(BEGIN)$(CUT)$(YELLOW)🧹Cleaning object files...$(RESET)"
	@rm -rf $(OBJ)

fclean	:
	@echo "$(UP)$(BEGIN)$(CUT)$(ORANGE)🔥Full clean, removing executable...$(RESET)"
	@rm -rf $(OBJ)
	@rm -f $(NAME)

re		: fclean all

.PHONY : all clean fclean re
