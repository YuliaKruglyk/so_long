# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:18:38 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/08/01 17:22:57 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -o so_long -g -framework OpenGL -framework AppKit -lmlx
RMFOR1337 = rm -rf a.out
RM = @rm -rf
BSRC = $(shell find bonus/game -name "b_*.c") 
# LIBFT = libft.a
# LIBFTPATH = ./libft/

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all:
	$(CC) ./game/*.c $(FLAGS)
	make -C ./game 

bonus:
	$(CC) ./bonus/game/*.c $(FLAGS)
	make -C ./bonus/

	$(RMFOR1337)
	
bclean:
	$(RM) ./bonus/so_long_bonus ./bonus/so_long_bonus.dSYM
	$(RM) ./bonus/game/*.o ./bonus/game/game

bfclean: bclean

clean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./game/*.o ./game/game
	
fclean: clean
	$(RM) ./game/*.a ./game/game
	$(RM) ./bonus/so_long_bonus
	$(RM) ./bonus/so_long_bonus.dSYM
	
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	# make -C ${LIBFTPATH}
	# mv $(LIBFTPATH)${LIBFT} ${LIBFT}

.PHONY: re fclean clean bonus bclean bfclean all
