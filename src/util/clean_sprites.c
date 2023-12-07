/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:43:56 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 09:04:45 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_mlx(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void	clean_buffer(t_game *game, t_buffer *buffer)
{
	if (buffer->img)
	{
		mlx_destroy_image(game->mlx, buffer->img);
		buffer->img = NULL;
	}
	buffer->addr = NULL;
	buffer->bits_per_pixel = 0;
	buffer->line_length = 0;
	buffer->endian = 0;
	buffer->width = 0;
	buffer->height = 0;
}


void	clean_sprites(t_game *game)
{
	clean_sprites_player(game);
	clean_sprites_collectible(game);
	clean_sprites_enemies(game);
	clean_sprites_tiles(game);
	clean_sprites_exit(game);
	free(game->sprites);
	game->sprites = NULL;
}
