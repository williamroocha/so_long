/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:20 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/16 14:08:29 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_exit(t_game *game, int x, int y)
{
	if (game->nbr_exit == 0)
	{
		game->exit = ft_calloc(1, sizeof(t_exit));
		if (!game->exit)
			ft_error_handler("Error\nMemory alloc failed on: build_exit.\n");
		game->exit->coordinates = build_coordinates(game, x, y);
	}
	game->nbr_exit++;
}
