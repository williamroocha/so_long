/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:54:18 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/25 17:25:49 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_characters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->matrix[y][x] == 'P')
				build_player(game, x, y);
			else if (game->map->matrix[y][x] == 'M')
				build_enemy(game, x, y);
			else if (game->map->matrix[y][x] == 'C')
				build_collectible(game, x, y);
			else if (game->map->matrix[y][x] == 'E')
				build_exit(game, x, y);
			x++;
		}
		y++;
	}
}
