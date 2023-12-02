/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:25:18 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 17:34:11 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	fill(int y, int x, t_game *game, char to_fill)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width
		|| game->flood_fill->map[y][x] == to_fill)
		return ;
	if (game->flood_fill->map[y][x] == 'C')
		game->flood_fill->number_collectibles++;
	if (game->flood_fill->map[y][x] == 'E')
		game->flood_fill->number_exits++;
	if (game->flood_fill->map[y][x] == '1')
		return ;
	game->flood_fill->map[y][x] = to_fill;
	fill(y + 1, x, game, to_fill);
	fill(y - 1, x, game, to_fill);
	fill(y, x + 1, game, to_fill);
	fill(y, x - 1, game, to_fill);
}

int	flood_fill(t_game *game)
{
	game->flood_fill->number_collectibles = 0;
	game->flood_fill->number_exits = 0;
	fill(game->flood_fill->y, game->flood_fill->x, game, 'A');
	if (game->nbr_collectibles != game->flood_fill->number_collectibles
		|| game->nbr_exit != game->flood_fill->number_exits)
		return (0);
	return (1);
}
