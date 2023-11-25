/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:21:48 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/25 11:07:18 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_walls(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		draw(x, y, &game->sprites->tiles[1], game);
	else if (x == game->map->width - 1 && y == 0)
		draw(x, y, &game->sprites->tiles[2], game);
	else if (x == 0 && y == game->map->height - 1)
		draw(x, y, &game->sprites->tiles[3], game);
	else if (x == game->map->width - 1 && y == game->map->height - 1)
		draw(x, y, &game->sprites->tiles[4], game);
	else if (y == 0)
		draw(x, y, &game->sprites->tiles[5], game);
	else if (x == 0)
		draw(x, y, &game->sprites->tiles[6], game);
	else if (y == game->map->height - 1)
		draw(x, y, &game->sprites->tiles[7], game);
	else if (x == game->map->width - 1)
		draw(x, y, &game->sprites->tiles[8], game);
	else
		draw(x, y, &game->sprites->tiles[9], game);
}

void	draw_path(t_game *game, int x, int y)
{
	draw(x, y, &game->sprites->tiles[0], game);
}

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->matrix[y][x] == '1')
			{
				draw_walls(game, x, y);
			}
			else
				draw_path(game, x, y);
			x++;
		}
		y++;
	}
}
