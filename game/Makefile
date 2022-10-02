# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:18:38 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/08/02 10:04:46 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ../libft
HEADERS = -I includes -I libft

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
	@echo $(G)Compiling [$<]...$(X)

all: $(NAME)

$(NAME): $(OBJECTS) libft 
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@echo $(G)Finished [$(NAME)]$(X)
	@echo

libft:
	$(MAKE) -C $(LIBFT)
	@echo $(Y)Compiling lib [$(LIBFT)]...$(X)
	@echo $(G)Finished lib [$(LIBFT)]$(X)

compile: 
	$(CC) $(FLAGS) -g $(HEADERS) $(LIBFT) $(SRC) $(LIBFT)/libft.a $(DEBUG) -o $(NAME)  
	@echo $(Y)Compiling comp [$(LIBFT)]...$(X)
	@echo $(G)Finished comp [$(LIBFT)]$(X)
	
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
