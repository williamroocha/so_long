/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:44 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/25 13:49:52 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	finish_game(t_game *game)
{
	int	y;
	int	x;

	y = game->player->coordinates->y / BLOCK_PIXEL;
	x = game->player->coordinates->x / BLOCK_PIXEL;
	if (game->nbr_collectibles == 0 && game->map->matrix[y][x] == 'E')
	{
		ft_putstr_fd("You won!\n", 1);
		end_game(game);
	}
}

t_buffer	*get_exit_sprite(t_game *game)
{
	printf("%d	%d\n", game->nbr_collectibles, game->exit_animation_pos);
	if (game->nbr_collectibles == 5 && game->exit_animation_pos == 0)
	{
		if (game->exit_animation != E_END)
		{
			game->exit_animation += 1;
		}
		game->exit_animation_pos = 0;
	}
	else if (game->nbr_collectibles == 0)
	{
		printf("get_exit_sprite else\n");
		game->exit_animation_pos++;
	}
	return (&game->sprites->exit[game->exit_animation]);
}

void	draw_exit(t_game *game)
{
	draw(game->exit->coordinates->x / BLOCK_PIXEL, game->exit->coordinates->y
		/ BLOCK_PIXEL, get_exit_sprite(game), game);
}
