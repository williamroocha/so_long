/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:39:01 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 14:30:21 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_count_steps(t_game *game)
{
	char	*steps;
	char	*steps_window;

	steps = ft_itoa(game->player->steps);
	steps_window = ft_strjoin("Steps: ", steps);
	free(steps);
	mlx_string_put(game->mlx, game->window, (game->map->width * BLOCK_PIXEL)
		- BLOCK_PIXEL * 2, game->map->height + BLOCK_PIXEL / 2, 0xeee600,
		steps_window);
	free(steps_window);
}

t_buffer	*get_player_sprite(t_game *game)
{
	static int	arr_pos;
	static int	anim_inter;
	t_coord		*player_coordinates;
	t_coord		*player_previous_coordinates;

	player_coordinates = game->player->coordinates;
	player_previous_coordinates = game->player->previous_coordinates;
	if (anim_inter == 20)
	{
		if (player_coordinates->y != player_previous_coordinates->y
			|| player_coordinates->x != player_previous_coordinates->x)
		{
			arr_pos = player_walk_sprite(game);
		}
		anim_inter = 0;
	}
	else
		anim_inter++;
	return (&game->sprites->player[arr_pos]);
}

void	draw_player(t_game *game)
{
	dead_player(game);
	draw_count_steps(game);
	get_player_sprite(game);
	draw(game->player->coordinates->x / BLOCK_PIXEL,
		game->player->coordinates->y / BLOCK_PIXEL, get_player_sprite(game),
		game);
}
