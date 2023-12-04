/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:07:47 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/04 09:22:37 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_lst(void *item)
{
	if (item)
		free(item);
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

void	destroy_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		free(game->map->matrix[i]);
		i++;
	}
	free(game->map->matrix);
	i = 0;
	while (i < game->map->height)
	{
		free(game->flood_fill->map[i]);
		i++;
	}
	free(game->flood_fill->map);
	if (game && game->map)
	{
		ft_lstclear(&game->map->lst_map, clean_lst);
		ft_lstclear(&game->enemies, clean_enemy);
		ft_lstclear(&game->collectibles, clean_collectible);
	}
}

void	end_game(t_game *game)
{
	if (game)
		destroy_game(game);
	exit(EXIT_SUCCESS);
}
