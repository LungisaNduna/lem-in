# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnduna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 13:35:08 by lnduna            #+#    #+#              #
#    Updated: 2018/09/30 16:31:31 by lnduna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INC = ./inc/
HEADERS = ./inc/*

COMP = gcc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(HEADERS) myLib
	@$(COMP) -o $(NAME) -I./inc/ src/* libft/libft.a
	@echo "$(NAME) is ready to use."

myLib:
	@make -C ./libft/
	@cp ./libft/libft.h ./inc/

clean:
	@rm -rf lem-in.dSYM
	@make fclean -C ./libft/
	@echo "the extra stuff has been removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all
