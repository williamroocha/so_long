/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:07:47 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/05 10:56:15 by wiferrei         ###   ########.fr       */
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

void	clean_exit(t_game *game)
{
	if (game->exit->coordinates)
		free(game->exit->coordinates);
	if (game->exit)
		free(game->exit);
}

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

void	destroy_game(t_game *game)
{
	int	i;

	if (game->player)
		clean_player(game->player);
	if (game->exit)
		clean_exit(game);
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->matrix[i])
			free(game->map->matrix[i]);
		i++;
	}
	if (game->map->matrix)
		free(game->map->matrix);
	i = 0;
	while (i < game->map->height)
	{
		if ((game->flood_fill->map[i]))
			free(game->flood_fill->map[i]);
		i++;
	}
	if (game->flood_fill->map)
		free(game->flood_fill->map);
	if (game->flood_fill)
		free(game->flood_fill);
	if (game)
	{
		ft_lstclear(&game->map->lst_map, clean_lst);
		ft_lstclear(&game->enemies, clean_enemy);
		ft_lstclear(&game->collectibles, clean_collectible);
		if (game->map)
			free(game->map);
	}
}

void	end_game(t_game *game)
{
	if (game)
		destroy_game(game);
	exit(EXIT_SUCCESS);
}
