/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:45 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 11:51:47 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_right_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = coord->y / BLOCK_PIXEL;
	x = (coord->x + BLOCK_PIXEL) / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_left_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = coord->y / BLOCK_PIXEL;
	x = (coord->x - BLOCK_PIXEL) / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_top_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = (coord->y - BLOCK_PIXEL) / BLOCK_PIXEL;
	x = coord->x / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_down_wall(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = (coord->y + BLOCK_PIXEL) / BLOCK_PIXEL;
	x = coord->x / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == '1');
}

int	is_exit(t_game *game, t_coord *coord)
{
	int	y;
	int	x;

	y = coord->y / BLOCK_PIXEL;
	x = coord->x / BLOCK_PIXEL;
	return (game->map->matrix[y][x] == 'E');
}
