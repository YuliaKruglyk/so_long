/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:05:46 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/02 10:01:27 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "../libft/libft.h"

int	linelen(int fd)
{
	char	buf[0];
	int		len;
	int		bytes;

	buf[0] = '\0';
	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buf, 1);
		if (buf[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

int	linecount(int fd)
{
	int		count;
	char	buf[0];
	int		bytes;

	buf[0] = '\0';
	count = 1;
	while (1)
	{
		bytes = read(fd, buf, 1);
		if (bytes < 1)
			break ;
		if (buf[0] == '\n')
			count++;
	}
	return (count);
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	error(BOLDRED"The game has been terminated\n"ENDC, game);
	map_destroy(game);
	exit(0);
}

void	window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(RED"Error\nFile not found\n"ENDC, data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error(RED"Error\nYour map does not have a .ber extension\n"ENDC, data);
	data->xsize = linelen(fd) * 48;
	data->ysize = linecount(fd) * 48;
}
