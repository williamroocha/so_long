/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:41:52 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/08 13:29:38 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_game *game)
{
	if (game->map->height == game->map->width)
		error_handler("Error\nInvalid map, wrong size or empty map.\n", game);
	if (!check_map_characters(game))
		error_handler("Error\nInvalid map, wrong characters.\n", game);
	if (!check_map_walls(game))
		error_handler("Error\nInvalid map, missing walls.\n", game);
	if (game->nbr_exit != 1)
		error_handler("Error\nInvalid map, missing exit.\n", game);
	if (game->nbr_player == 0)
		error_handler("Error\nInvalid map, missing player.\n", game);
	if (game->nbr_player > 1)
		error_handler("Error\nInvalid map, too many players.\n", game);
	if (game->nbr_collectibles == 0)
		error_handler("Error\nInvalid map, missing collectibles.\n", game);
	if (!flood_fill(game))
		error_handler("Error\nInvalid map, not suported.\n", game);
}
