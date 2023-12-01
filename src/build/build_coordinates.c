/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:02:49 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/01 15:39:32 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Allocate memory for a t_coord structure.
// Initialize the x and y coordinates.
// Return the pointer to the structure.

t_coord	*build_coordinates(t_game *game, int x, int y)
{
	t_coord	*coord;

	coord = ft_calloc(1, sizeof(t_coord));
	if (!coord)
		error_handler("Error\nMemory alloc failed (in build_coordinates)\n",
			game);
	coord->x = x * BLOCK_PIXEL;
	coord->y = y * BLOCK_PIXEL;
	return (coord);
}
