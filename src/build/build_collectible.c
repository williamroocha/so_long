/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:44:39 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/03 12:45:56 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_collectible(t_game *game, int x, int y)
{
	t_collectible	*collectible;

	collectible = ft_calloc(1, sizeof(t_collectible));
	if (!collectible)
		error_handler("Error\nMemory alloc failed on: build_collectible\n",
			game);
	collectible->coordinates = build_coordinates(game, x, y);
	collectible->collected = 0;
	collectible->animation = 0;
	collectible->animation_position = 0;
	game->nbr_collectibles++;
	ft_lstadd_back(&game->collectibles, ft_lstnew(collectible));
}
