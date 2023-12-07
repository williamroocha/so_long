/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:07:47 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 08:49:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_lst(void *item)
{
	if (item)
		free(item);
}

void	destroy_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map);
		if (game->flood_fill)
			clean_flood_fill(game->flood_fill);
		if (game->enemies)
			ft_lstclear(&game->enemies, clean_enemy);
		if (game->collectibles)
			ft_lstclear(&game->collectibles, clean_collectible);
		if (game->mlx && game->image_buffer.img)
			mlx_destroy_image(game->mlx, game->image_buffer.img);
		if (game->sprites)
			clean_sprites(game);
		if (game->mlx)
			clean_mlx(game);
		if (game->player)
			clean_player(game->player);
		if (game->exit)
			clean_exit(game);
	}
}

void	end_game(t_game *game)
{
	if (game)
		destroy_game(game);
	exit(EXIT_SUCCESS);
}
