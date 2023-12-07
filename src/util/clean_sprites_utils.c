/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sprites_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:03:51 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 09:05:19 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_sprites_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_PLAYER)
	{
		clean_buffer(game, &game->sprites->player[i]);
		i++;
	}
}

void	clean_sprites_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_ENEMY)
	{
		clean_buffer(game, &game->sprites->enemy[i]);
		i++;
	}
}

void	clean_sprites_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_COLLECTIBLE)
	{
		clean_buffer(game, &game->sprites->collectible[i]);
		i++;
	}
}

void	clean_sprites_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_EXIT)
	{
		clean_buffer(game, &game->sprites->exit[i]);
		i++;
	}
}

void	clean_sprites_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_TILES)
	{
		clean_buffer(game, &game->sprites->tiles[i]);
		i++;
	}
}
