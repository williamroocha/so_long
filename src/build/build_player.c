/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:18:49 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/16 14:19:51 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Check if the player is the first player to be built.
// Allocate memory for the player structure.
// Allocate memory for the previous_coordinates of the player.
// Initialize the previous_coordinates of the player.
// Initialize the flood_fill coordinates with 
//  the initial coordinates of the player.
// Increment the number of players.

void	build_player(t_game *game, int x, int y)
{
	if (game->nbr_player == 0)
	{
		game->player = ft_calloc(1, sizeof(t_player));
		game->player->previous_coordinates = ft_calloc(1, sizeof(t_coord));
		if (!game->player || !game->player->previous_coordinates)
			ft_error_handler("Error\nMemory alloc on: build_player\n");
		game->player->previous_coordinates = build_coordinates(game, x, y);
		game->flood_fill->x = x;
		game->flood_fill->y = y;
	}
	game->nbr_player++;
}
