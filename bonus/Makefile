# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:18:38 by ykruhlyk          #+#    #+#              #
#    Updated: 2022/07/22 21:56:14 by ykruhlyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -o ./so_long_bonus -g -framework OpenGL -framework AppKit -L../minilibx -lmlx
RM = @rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

bonus:
	@echo $(B)[Bonus Linking Started]$(B)
	$(CC) ./game/*.c $(FLAGS)
	make -C ./game

fclean:
	$(RM)  so_long_bonus so_long_bonus.dSYM
	$(RM) ./game/*.o ./game/game
	@echo $(R)Removed [TEMPORARY FILES]$(X)
	@echo $(R)Removed [./game/*.o]$(X)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: re