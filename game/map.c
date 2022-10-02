/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:17:15 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/01 17:49:26 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_build(t_game *game, int i)
{
	int			j;
	t_texture	map;
	t_image		image;

	image.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_texture(game->map[i][j]);
			image.path = map.path;
			img_put(image, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	background_build(t_game game, int i)
{
	int		j;
	t_image	image;

	image.wlx = game;
	j = 0;
	if (ft_strlen(game.map[i]) != game.xsize / 48 && i != (game.ysize / 48))
		error(RED"The map is not rectangularn"ENDC, &game);
	if (game.map[(game.ysize / 48)] && game.map[(game.ysize / 48)][0] != '\0')
		error(RED"Wrong Map\n"ENDC, &game);
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (!(ft_strchr("1PCE0", game.map[i][j])))
				error(RED"Error\nForeign problem\n"ENDC, &game);
			image.path = "./img/background48.xpm";
			img_put(image, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	maplen(char *line, t_game *game, int i)
{
	int		j;
	t_image	image;

	image.wlx = *game;
	j = 0;
	if (line[ft_strlen(line - 1) == '\n'])
		game->map[i] = calloc(ft_strlen(line), sizeof(char));
	else
		game->map[i] = calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[j])
	{
		if (line[j] == '\n')
			break ;
		game->map[i][j] = line[j];
		j++;
	}
	if (line[0])
		free (line);
	background_build(*game, i);
	map_build(game, i);
}

void	map_gnl(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	game->map = calloc(game->ysize / 48 + 1, sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->ysize / 48)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		maplen(line, game, i);
		i++;
	}
	close(fd);
}

void	map_destroy(t_game	*game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
}
