/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:21:48 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 17:22:30 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
				draw(x, y, &game->sprites->tiles[1], game);
			else
				draw(x, y, &game->sprites->tiles[0], game);
			x++;
		}
		y++;
	}
}
