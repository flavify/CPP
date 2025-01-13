# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 04:17:13 by fvoicu            #+#    #+#              #
#    Updated: 2024/05/09 20:21:12 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= horde
CC				:= c++
FLAGS			:= -Wall -Wextra -Werror -std=c++98
SRC				:= main.cpp zombieHorde.cpp Zombie.cpp
OBJ				:= $(SRC:.cpp=.o)

# Colors
CYAN			:= \033[38;5;6m
GREEN			:= \033[0;32m
MAGENTA		:= \033[1;95m
RESET			:= \033[0m



# Cursor manipulation
UP				:= \033[A
CUT				:= \033[K
BEGIN			:= \033[0G

all: $(NAME)

$(NAME)		: $(OBJ)
	@./progressbar.sh
	@printf "\n"
	@./spin.sh
	@printf "$(UP)$(BEGIN)$(CUT)Compiling $@...$(RESET)\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Zombies are ready to rise✅$(RESET)\n"
	@./progressbar.sh

%.o				: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean			:
	@printf "\n"
	@rm -rf $(OBJ)
	@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)Objects removed successfully🧽$(RESET)\n"

fclean		: clean
	@rm -f $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)All cleaned up🚽✨$(RESET)\n"

re				: fclean all

.PHONY		: all clean fclean re