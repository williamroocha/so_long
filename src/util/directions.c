/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:38:30 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/26 20:05:10 by wiferrei         ###   ########.fr       */
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

void	move_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;
	int		move;

	move = 0;
	lst = game->enemies;
	while (lst)
	{
		enemy = ((t_enemy *)lst->content);
		move = rand() % 450;
		if (move == 1)
			move_left(game, enemy->coordinates, enemy->previous_coordinates, 0);
		else if (move == 2)
			move_right(game, enemy->coordinates, enemy->previous_coordinates,
				0);
		else if (move == 3)
			move_up(game, enemy->coordinates, enemy->previous_coordinates, 0);
		else if (move == 4)
			move_down(game, enemy->coordinates, enemy->previous_coordinates, 0);
		if (!enemy && !game)
			return ;
		lst = lst->next;
	}
}
