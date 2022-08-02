# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:18:38 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/08/02 10:35:38 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

# LIBFT = libft.a
# LIBFTPATH = ../libft/

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

PCFILES = $(shell find ./printf -name "*.c")

OBJECTS = $(CFILES:.c=.o) $(PCFILES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)
	@echo $(G)Compiling [$<]...$(X)

all: $(NAME)

$(NAME): $(OBJECTS)
	# make -C ${LIBFTPATH}
	# mv $(LIBFTPATH)${LIBFT} ${LIBFT}
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@echo $(G)Finished [$(NAME)]$(X)
	@echo

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
