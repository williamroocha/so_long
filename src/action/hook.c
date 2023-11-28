/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:48:29 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/28 08:06:55 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	closing_game(t_game *game)
{
	ft_putstr_fd("Bye!\n", 1);
	end_game(game);
	return (0);
}

int	loop(t_game *game)
{
	draw_background(game);
	draw_collectible(game);
	draw_exit(game);
	draw_enemy(game);
	move_enemy(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image_buffer.img, 0,
		0);
	draw_player(game);
	return (EXIT_SUCCESS);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == LETTER_KEY_EXIT)
	{
		ft_putstr_fd("Bye!\n", 1);
		end_game(game);
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

void	register_hook(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->window, 17, 0, closing_game, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
