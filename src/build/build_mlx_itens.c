/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mlx_itens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:30:10 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/25 17:32:46 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_mlx_itens(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * BLOCK_PIXEL,
			game->map->height * BLOCK_PIXEL, WINDOW_TITLE);
	game->image_buffer.img = mlx_new_image(game->mlx, game->map->width
			* BLOCK_PIXEL, game->map->height * BLOCK_PIXEL);
	game->image_buffer.addr = mlx_get_data_addr(game->image_buffer.img,
			&game->image_buffer.bits_per_pixel, &game->image_buffer.line_length,
			&game->image_buffer.endian);
	game->image_buffer.width = game->map->width * BLOCK_PIXEL;
	game->image_buffer.height = game->map->height * BLOCK_PIXEL;
}
