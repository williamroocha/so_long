/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:15:25 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/27 10:12:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_walk_sprite_left(t_game *game)
{
	if (game->player->animation == PSL_END)
		game->player->animation = PSL_START_RUN;
	else if (game->player->animation >= PSL_START_RUN
		&& game->player->animation <= PSL_END)
		game->player->animation += 1;
	else
		game->player->animation = PSL_START_RUN;
}

void	player_walk_sprite_right(t_game *game)
{
	if (game->player->animation == PSR_END)
		game->player->animation = PSR_START_RUN;
	else if (game->player->animation >= PSR_START_RUN
		&& game->player->animation <= PSR_END)
		game->player->animation += 1;
	else
		game->player->animation = PSR_START_RUN;
}

void	player_walk_sprite_down(t_game *game)
{
	if (game->player->animation == PSD_END)
		game->player->animation = PSD_START_RUN;
	else if (game->player->animation >= PSD_START_RUN
		&& game->player->animation <= PSD_END)
		game->player->animation += 1;
	else
		game->player->animation = PSD_START_RUN;
}

void	player_walk_sprite_up(t_game *game)
{
	if (game->player->animation == PSD_END)
		game->player->animation = PSU_START_RUN;
	else if (game->player->animation >= PSU_START_RUN
		&& game->player->animation <= PSU_END)
		game->player->animation += 1;
	else
		game->player->animation = PSU_START_RUN;
}

int	player_walk_sprite(t_game *game)
{
	if (game->player->coordinates->x > game->player->previous_coordinates->x)
		player_walk_sprite_left(game);
	else if (game->player->coordinates->x < game->player->previous_coordinates->x)
		player_walk_sprite_right(game);
	else if (game->player->coordinates->y > game->player->previous_coordinates->y)
		player_walk_sprite_down(game);
	else if (game->player->coordinates->y < game->player->previous_coordinates->y)
		player_walk_sprite_up(game);
	game->player->previous_coordinates->y = game->player->coordinates->y;
	game->player->previous_coordinates->x = game->player->coordinates->x;
	return (game->player->animation);
}