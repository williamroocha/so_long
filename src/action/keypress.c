/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:42:26 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 13:24:57 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == LETTER_KEY_EXIT)
	{
		closing_game(game);
	}
	else
	{
		if (keycode == LETTER_KEY_LEFT || keycode == ARROW_KEY_LEFT)
			move_left(game, game->player->coordinates,
				game->player->previous_coordinates, 1);
		else if (keycode == LETTER_KEY_RIGHT || keycode == ARROW_KEY_RIGHT)
			move_right(game, game->player->coordinates,
				game->player->previous_coordinates, 1);
		else if (keycode == LETTER_KEY_UP || keycode == ARROW_KEY_UP)
			move_up(game, game->player->coordinates,
				game->player->previous_coordinates, 1);
		else if (keycode == LETTER_KEY_DOWN || keycode == ARROW_KEY_DOWN)
			move_down(game, game->player->coordinates,
				game->player->previous_coordinates, 1);
		get_item(game);
		finish_game(game);
	}
	return (0);
}
