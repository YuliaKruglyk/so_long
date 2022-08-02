# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:18:38 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/08/01 15:28:10 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = $(shell find . -name "*.c")

OBJECTS = $(CFILES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$<]...$(X)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@echo $(G)Finished [$(NAME)]$(X)
	@echo

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re