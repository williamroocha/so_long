/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:21:48 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/22 17:14:24 by wiferrei         ###   ########.fr       */
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
			if(x == 0 || y == 0 || x == game->map->width - 1 || y == game->map->height - 1)
			{
				draw(x, y, &game->sprites->tiles[1], game);
			}
			else
				draw(x, y, &game->sprites->tiles[0], game);		
		
			x++;
		}			
		y++;
	}
}
