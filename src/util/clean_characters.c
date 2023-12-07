/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:11:07 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 19:10:42 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_player(void *item)
{
	t_player	*player;

	if (item)
	{
		player = (t_player *)item;
		if (player->coordinates)
			free(player->coordinates);
		if (player->previous_coordinates)
			free(player->previous_coordinates);
		free(player);
	}
}

void	clean_enemy(void *item)
{
	t_enemy	*enemy;

	if (item)
	{
		enemy = (t_enemy *)item;
		if (enemy->coordinates)
			free(enemy->coordinates);
		if (enemy->previous_coordinates)
			free(enemy->previous_coordinates);
		free(enemy);
	}
}

void	clean_collectible(void *item)
{
	t_collectible	*collectible;

	if (item)
	{
		collectible = (t_collectible *)item;
		if (collectible->coordinates)
			free(collectible->coordinates);
		free(collectible);
	}
}

void	clean_exit(t_game *game)
{
	if (game->exit)
	{
		if (game->exit->coordinates)
			free(game->exit->coordinates);
		free(game->exit);
	}
}
