/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:26:10 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/01 17:24:52 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*img_put(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
			image.path, &image.width, &image.height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_texture	set_texture(char name)
{
	t_texture	imgs[6];
	int			i;

	imgs[0] = (t_texture){"1", "./img/wall48.xpm"};
	imgs[1] = (t_texture){"0", "./img/background48.xpm"};
	imgs[2] = (t_texture){"C", "./img/item4.xpm"};
	imgs[3] = (t_texture){"P", "./img/player4.xpm"};
	imgs[4] = (t_texture){"E", "./img/exit48.xpm"};
	imgs[5] = (t_texture){NULL, NULL};
	i = 0;
	while (imgs[i].file != NULL)
	{
		if (imgs[i].file[0] == name)
		{
			return (imgs[i]);
			break ;
		}
		i++;
	}
	return (imgs[5]);
}

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		up(game);
	if (key_code == RIGHT)
		right(game);
	if (key_code == LEFT)
		left(game);
	if (key_code == DOWN)
		down(game);
	return (0);
}

void	start(t_game *game)
{
	game->check_collect = 0;
	game->check_exit = 0;
	game->collect = 0;
	game->move = 0;
	game->check_player = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		error(RED"You can only enter 2 arguments\n", &game);
	window_size(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.xsize, game.ysize, "Hungry Chick");
	start(&game);
	map_gnl(&game, argv);
	check_game(&game);
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_check, &game);
	mlx_loop(game.mlx);
}
