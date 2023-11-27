/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:39:01 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/27 10:38:31 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../..//includes/so_long.h"

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

void	draw_count_steps(t_game *game)
{
	char	*steps;
	char	*steps_window;

	steps = ft_itoa(game->player->steps);
	steps_window = ft_strjoin("steps: ", steps);
	free(steps);
	mlx_string_put(game->mlx, game->window, (game->map->width * BLOCK_PIXEL)
		- BLOCK_PIXEL * 2, game->map->height + BLOCK_PIXEL / 2, 0x0000000,
		steps_window);
	free(steps_window);
}

//  Mudar nome dessas variavesis;

t_buffer	*get_player_sprite(t_game *game)
{
	static int	arr_pos;
	static int	anim_inter;

	printf("get_player_sprite\n");
	if (anim_inter == 20)
	{
		// error here
		printf("error here\n");
		printf("%d\n", game->player->coordinates->y);
		printf("%d\n", game->player->previous_coordinates->y);
		printf("%d\n", game->player->coordinates->x);
		printf("%d\n", game->player->previous_coordinates->x);
		// if (game->player->coordinates->y != game->player->previous_coordinates->y
		// 	|| game->player->coordinates->x != game->player->previous_coordinates->x)
		// {
		// 	arr_pos = player_walk_sprite(game);
		// }
		// anim_inter = 0;
	}
	else
		anim_inter++;
	return (&game->sprites->player[arr_pos]);
}

void	draw_player(t_game *game)
{
	// dead_player(game);
	draw_count_steps(game);
	get_player_sprite(game);
	// draw(game->player->coordinates->x / BLOCK_PIXEL,
	// 	game->player->coordinates->y / BLOCK_PIXEL, get_player_sprite(game),
	// 	game);
}
