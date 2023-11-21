/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:52:17 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 17:53:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_buffer	*get_enemy_sprite(t_enemy *enemy, t_game *game)
{
	if (enemy->animation == 50)
	{
		if (enemy->animation_position == ENEMY_END)
		{
			enemy->animation_position = ENEMY_START;
		}
		else
			enemy->animation_position += 1;
		enemy->animation = 0;
	}
	else
		enemy->animation++;
	return (&game->sprites->enemy[enemy->animation_position]);
}

void	draw_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;

	lst = game->enemies;
	while (lst)
	{
		enemy = (t_enemy *)lst->content;
		draw(enemy->coordinates->x / BLOCK_PIXEL, enemy->coordinates->y
			/ BLOCK_PIXEL, get_enemy_sprite(enemy, game), game);
		lst = lst->next;
	}
}
