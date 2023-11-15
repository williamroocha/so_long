/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:09:50 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 18:12:09 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map->width)
	{
		if (game->map->matrix[0][x] != '1'
			|| game->map->matrix[game->map->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < game->map->height)
	{
		if (game->map->matrix[y][0] != '1'
			|| game->map->matrix[y][game->map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
