/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:42:48 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 07:45:07 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_game(t_game *game)
{
	game->map = NULL;
	game->flood_fill = NULL;
	game->sprites = NULL;
	game->exit_animation_pos = E_START;
	game->exit_animation = E_START;
	game->enemies = NULL;
	game->collectibles = NULL;
	game->nbr_collectibles = 0;
	game->player = NULL;
	game->nbr_player = 0;
	game->exit = NULL;
	game->nbr_exit = 0;
	game->mlx = NULL;
}
