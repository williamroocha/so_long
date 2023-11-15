/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:41:52 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 18:13:26 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_game *game)
{
	printf("Checking map...\n");
	if (game->map->height == game->map->width)
		ft_error_handler("Error\nInvalid map, wrong size.\n");
	if (!check_map_characters(game))
		ft_error_handler("Error\nInvalid map, wrong characters.\n");
	if (!check_map_walls(game))
		ft_error_handler("Error\nInvalid map, missing walls.\n");
}
