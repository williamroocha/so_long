/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:09:19 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/26 09:37:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = ft_calloc(1, sizeof(t_enemy));
	if (!enemy)
		ft_error_handler("Error\nMemory alloc failed on: build_enemy.\n");
	enemy->coordinates = build_coordinates(game, x, y);
	enemy->previous_coordinates = ft_calloc(1, sizeof(t_coord));
	if (!enemy->previous_coordinates)
		ft_error_handler("Error\nMemory alloc failed on: enemy->prev coord.\n");
	if (game->enemies == NULL)
		game->enemies = ft_lstnew(enemy);
	else
		ft_lstadd_back(&game->enemies, ft_lstnew(enemy));
	game->nbr_enemies++;
}
