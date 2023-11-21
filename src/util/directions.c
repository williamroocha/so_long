/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:38:30 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 16:34:08 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_right(t_game *game, t_coord *coord, t_coord *last_coord,
		int is_player)
{
	if (coord->x < (game->map->width * BLOCK_PIXEL) && !is_right_wall(game,
			coord))
	{
		last_coord->x = coord->x;
		coord->x += BLOCK_PIXEL;
		if (is_player)
			game->player->steps++;
	}
}

void	move_left(t_game *game, t_coord *coord, t_coord *last_coord,
		int is_player)
{
	if (coord->x > 0 && !is_left_wall(game, coord))
	{
		last_coord->x = coord->x;
		coord->x -= BLOCK_PIXEL;
		if (is_player)
			game->player->steps++;
	}
}

void	move_up(t_game *game, t_coord *coord, t_coord *last_coord,
		int is_player)
{
	if (coord->y > 0 && !is_top_wall(game, coord))
	{
		last_coord->y = coord->y;
		coord->y -= BLOCK_PIXEL;
		if (is_player)
			game->player->steps++;
	}
}

void	move_down(t_game *game, t_coord *coord, t_coord *last_coord,
		int is_player)
{
	if (coord->y < (game->map->height * BLOCK_PIXEL) && !is_down_wall(game,
			coord))
	{
		last_coord->y = coord->y;
		coord->y += BLOCK_PIXEL;
		if (is_player)
			game->player->steps++;
	}
}