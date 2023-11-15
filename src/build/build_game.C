/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:31:14 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 18:32:28 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_game(t_game *game)
{
	game->exit_animation_pos = E_START;
	game->exit_animation = E_START;
	game->enemies = NULL;
	game->collectibles = NULL;
	game->total_collectibles = 0;
	game->nbr_player = 0;
	game->nbr_exit = 0;
	game->mlx = NULL;
}
