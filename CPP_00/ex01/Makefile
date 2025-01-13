# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 04:53:35 by fvoicu            #+#    #+#              #
#    Updated: 2024/04/23 17:27:56 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= phonebook
CC				:= c++
FLAGS			:= -Wall -Wextra -Werror -std=c++98
SRC				:= main.cpp Contact.cpp PhoneBook.cpp
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
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)PhoneBook compiled successfully✅$(RESET)\n"
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
