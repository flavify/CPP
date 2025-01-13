# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 04:28:12 by fvoicu            #+#    #+#              #
#    Updated: 2024/04/23 16:35:57 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=		megaphone
CC			:=		c++
FLAGS		:=		-Wall -Wextra -Werror -std=c++98
SRC			:=		main.cpp
OBJ			:=		$(SRC:.cpp=.o)

# Colors
CYAN		:= \033[38;5;6m
GREEN		:= \033[0;32m
MAGENTA	:= \033[0;95m
RESET		:= \033[0m

#Cursor manipulation
UP			:= \033[A
CUT			:= \033[K
BEGIN		:= \033[0G

all			: $(NAME)

$(NAME)	: $(OBJ)
	@./progressbar.sh
	@printf "\n"
	@./spin.sh
	@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)Compiling:$<...$(RESET)\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(GREEN)Megaphone compiled successfully✅$(RESET)\n"
	@./progressbar.sh

$(OBJ)	: $(SRC)
	@$(CC) $(FLAGS) -c $< -o $@

clean		:
		@printf "\n"
		@rm -rf $(OBJ)
		@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)Objects removed successfully🧽$(RESET)"
		@printf "\n"

fclean	: clean
		@rm -f $(NAME)
		@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)All cleaned up🚽✨$(RESET)\n"

re			: fclean all

.PHONY	: all clean fclean re
