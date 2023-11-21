/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:41:52 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 13:03:42 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_game *game)
{
	if (game->map->height == game->map->width)
		ft_error_handler("Error\nInvalid map, wrong size.\n");
	if (!check_map_characters(game))
		ft_error_handler("Error\nInvalid map, wrong characters.\n");
	if (!check_map_walls(game))
		ft_error_handler("Error\nInvalid map, missing walls.\n");
	if (game->nbr_exit != 1)
		ft_error_handler("Error\nInvalid map, missing exit.\n");
	if (game->nbr_player == 0)
		ft_error_handler("Error\nInvalid map, missing player.\n");
	if (game->nbr_player > 1)
		ft_error_handler("Error\nInvalid map, too many players.\n");
	if (game->nbr_collectibles == 0)
		ft_error_handler("Error\nInvalid map, missing collectibles.\n");
}

// Maybe use flood fill to check if the map is empty?