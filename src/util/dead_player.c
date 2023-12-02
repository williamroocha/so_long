/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:10:43 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 13:11:00 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	dead_player(t_game *game)
{
	t_list	*lst;
	t_enemy	*enemy;

	lst = game->enemies;
	while (lst)
	{
		enemy = (t_enemy *)lst->content;
		if (enemy->coordinates->x == game->player->coordinates->x
			&& enemy->coordinates->y == game->player->coordinates->y)
		{
			ft_putstr_fd("You died\n", 1);
			end_game(game);
		}
		lst = lst->next;
	}
}
