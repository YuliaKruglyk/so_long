/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:52:39 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/01 15:23:46 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	animation(t_game *game)
{
	int				i;
	unsigned long	j;

	i = 0;
	while (i < game->ysize / 48)
	{
		j = 0;
		while (j < game->xsize/ 48)
		{
			if (game->map[i][j] == 'N')
				enemy_touch(game, j, i);
			if (game->map[i][j] == 'C')
				collect_anim(game, j, i);
			j++;
		}
		i++;
	}
	game->enemy_index++;
}

int	animation_speed(t_game	*game)
{
	game->enemy_speed++;
	if (game->enemy_speed >= 3000)
	{
		animation(game);
		game->enemy_speed = 0;
	}
	return (0);
}
 