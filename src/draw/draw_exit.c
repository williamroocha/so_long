/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:44 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 16:32:39 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	finish_game(t_game *game)
{
	int	y;
	int	x;

	y = game->player->coordinates->y / BLOCK_PIXEL;
	x = game->player->coordinates->x / BLOCK_PIXEL;
	if (game->nbr_collectibles == 0 && game->map->matrix[y][x] == 'E')
	{
		ft_putstr_fd("You won!\n", 1);
		end_game(game);
	}
}
