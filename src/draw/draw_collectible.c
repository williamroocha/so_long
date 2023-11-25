/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:04:08 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/25 17:50:55 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_item(t_game *game)
{
	t_list			*lst;
	t_collectible	*collectible;
	int				y;
	int				x;

	lst = game->collectibles;
	y = game->player->coordinates->y / BLOCK_PIXEL;
	x = game->player->coordinates->x / BLOCK_PIXEL;
	if (game->map->matrix[y][x] == 'C')
	{
		while (lst)
		{
			collectible = (t_collectible *)lst->content;
			if (collectible->coordinates->x == game->player->coordinates->x
				&& collectible->coordinates->y == game->player->coordinates->y
				&& collectible->collected == 0)
			{
				collectible->collected = 1;
				game->nbr_collectibles--;
			}
			lst = lst->next;
		}
	}
}

t_buffer	*get_collectible_sprite(t_collectible *collectible, t_game *game)
{
	if (collectible->animation_position == 4)
	{
		if (collectible->animation == C_END)
		{
			collectible->animation = C_START;
		}
		else
			collectible->animation += 1;
		collectible->animation_position = 0;
	}
	else
		collectible->animation_position++;
	return (&game->sprites->collectible[collectible->animation]);
}

void	draw_collectible(t_game *game)
{
	t_list			*lst;
	t_collectible	*collectible;

	lst = game->collectibles;
	while (lst)
	{
		collectible = (t_collectible *)lst->content;
		if (collectible->collected == 0)
		{
			draw(collectible->coordinates->x / BLOCK_PIXEL, collectible->coordinates->y
				/ BLOCK_PIXEL, get_collectible_sprite(collectible, game), game);
		}
		lst = lst->next;
	}
}
