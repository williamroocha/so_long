/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:48:29 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/01 17:48:39 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->window, 17, 0, closing_game, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
