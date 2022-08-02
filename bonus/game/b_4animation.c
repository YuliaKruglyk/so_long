/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_4animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:02:54 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/01 17:32:02 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	bonus_update(t_game *game, int x, int y)
{
	t_image	image;

	image.path = "./img/beige.xpm";
	image.wlx = *game;
	img_put(image, x, y);
}

void	enemy_move(t_game *game, int x, int y)
{
	int		i;
	int		j;
	t_image	image;

	image.wlx = *game;
	image.path = "./img/guillaume.xpm";
	while (game->map[y][x + 1] != '1')
	{
		bonus_update(game, (x * 48), y * 48);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'N';
		i = y * 48;
		j = (x * 48) + 48;
		img_put(image, j, i);
		x++;
	}	
}

void	enemy_touch(t_game *game, int x, int y)
{
	int i;
	int j;
	t_image image;
	
	image.wlx = *game;
	image.path = "./img/guillaume.xpm";
	if (x * 48 == game->posx && y * 48 == game->posy)
		error(RED"Community service!\n", game);
	if (game->map[y][x-1] != '1')
	{
		bonus_update(game, (x * 48), y * 48);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'N';
		i = y * 48;
		j = (x * 48) - 48;
		img_put(image, j, i);
	}
	else if (game->map[y][x + 1] == '0')
		enemy_move(game, x, y);
}

void	collect_anim(t_game *game, int x, int y)
{
	t_image image;

	if (game->enemy_index >= 2)
		game->enemy_index = 0;
	image.wlx = *game;
	if (game->enemy_index == 0)
	{
		image.path = "./img/beige.xpm";
		img_put(image, x * 48, y * 48);
		image.path = "./img/bottle.xpm";
		img_put(image, x * 48, y * 48);
	}
	if (game->enemy_index == 1)
	{
		image.path = "./img/beige.xpm";
		img_put(image, x * 48, y * 48);
		image.path = "./img/id.xpm";
		img_put(image, x * 48, y * 48);
	}
}
