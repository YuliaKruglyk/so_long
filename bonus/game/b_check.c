/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:58:25 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/02 19:33:17 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	error(char *msg, t_game *game)
{
	printf("%s", msg);
	map_destroy(game);
	exit(0);
}

void	check_wall(t_game *game)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < (game->ysize / SIZE))
	{
		x = 0;
		while (x < (game->xsize / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				error("Error\nThe map must be surrounded by walls\n", game);
			else if ((y == (game->ysize / SIZE - 1)
					|| x == (game->xsize / SIZE - 1))
				&& game->map[y][x] != '1')
				error("Error\nThe map must be surrounded by walls\n", game);
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->ysize / 48)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->check_exit++;
			if (game->map[y][x] == 'N')
				game->check_enemy++;
			x++;
		}
		y++;
	}
	if (game->check_collect == 0)
		error(RED"You didn`t leave bottle in cluster!\n"ENDC, game);
	if (game->check_enemy == 0)
		error(RED"Guillaume on holiday!\n"ENDC, game);
	if (game->check_exit == 0)
		error("Error\nThere is no exit door on the map!\n", game);
	if (game->check_player != 1)
		error("Error\nYou can only have 1 character!\n", game);
}

void	check_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->ysize / 48)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
					game->check_collect++;
			if (game->map[y][x] == 'P')
			{
				game->posx = x * SIZE;
				game->posy = y * SIZE;
				game->check_player++;
			}
			x++;
		}
		y++;
	}
	check_map(game);
	check_wall(game);
}

int	check_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	else if (game->map[y][x] == 'N')
		error("You got community service!", game);
	else if (game->map[y][x] == 'C')
	{
		game->collect++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->collect != game->check_collect)
		{
			printf(RED"Don`t leave your ID and bottle in cluster!\n"ENDC);
			return (1);
		}
		error(GREEN"Congratulations!!! You didn`t get community service!\n"ENDC, game);
		return (0);
	}
	return (0);
}
