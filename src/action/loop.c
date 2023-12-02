/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:44:25 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 11:59:31 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	loop(t_game *game)
{
	draw_background(game);
	draw_collectible(game);
	draw_exit(game);
	draw_enemy(game);
	move_enemy(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0,
		0);
	draw_player(game);
	return (EXIT_SUCCESS);
}
