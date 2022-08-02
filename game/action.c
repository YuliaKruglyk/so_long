/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:37:03 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/02 10:36:50 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.path = "./img/background48.xpm";
	image.wlx = *game;
	img_put(image, game->posx, game->posy);
	img_put(image, x, y);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./img/right.xpm";
	image.wlx = *game;
	i = game->posy;
	j = game->posx + 48;
	if ((check_move(game, (i / 48), (j / 48)) != 1))
	{
		game->move++;
		ft_printf(GREEN"Step = %d\n"ENDC, game->move);
		update(game, j, i);
		game->posy = i;
		game->posx = j;
		img_put(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./img/left.xpm";
	image.wlx = *game;
	i = game->posy;
	j = game->posx - 48;
	if ((check_move(game, (i / 48), (j / 48)) != 1))
	{
		game->move++;
		printf(GREEN"Step = %d\n"ENDC, game->move);
		update(game, j, i);
		game->posy = i;
		game->posx = j;
		img_put(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./img/player4.xpm";
	image.wlx = *game;
	i = game->posy - 48;
	j = game->posx;
	if ((check_move(game, (i / 48), (j / 48)) != 1))
	{
		game->move++;
		printf(GREEN"Step = %d\n"ENDC, game->move);
		update(game, j, i);
		game->posy = i;
		game->posx = j;
		img_put(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./img/player4.xpm";
	image.wlx = *game;
	i = game->posy + 48;
	j = game->posx;
	if ((check_move(game, (i / 48), (j / 48)) != 1))
	{
		game->move++;
		printf(GREEN"Step = %d\n"ENDC, game->move);
		update(game, j, i);
		game->posy = i;
		game->posx = j;
		img_put(image, j, i);
	}
}
