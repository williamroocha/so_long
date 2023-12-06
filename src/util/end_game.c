/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:07:47 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/06 09:27:58 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_lst(void *item)
{
	if (item)
		free(item);
}

void	clean_collectible(void *item)
{
	t_collectible	*collectible;

	if (item)
	{
		collectible = (t_collectible *)item;
		if (collectible->coordinates)
			free(collectible->coordinates);
		free(collectible);
	}
}

void	clean_enemy(void *item)
{
	t_enemy	*enemy;

	if (item)
	{
		enemy = (t_enemy *)item;
		if (enemy->coordinates)
			free(enemy->coordinates);
		if (enemy->previous_coordinates)
			free(enemy->previous_coordinates);
		free(enemy);
	}
}

void	clean_exit(t_game *game)
{
	if (game->exit)
	{
		if (game->exit->coordinates)
			free(game->exit->coordinates);
		free(game->exit);
	}
}
void	clean_map(t_map *map)
{
	int	i;

	if (map)
	{
		i = 0;
		if (map->height)
		{
			while (i < map->height)
			{
				if (map->matrix[i])
					free(map->matrix[i]);
				i++;
			}
		}
		if (map->lst_map)
			ft_lstclear(&map->lst_map, clean_lst);
		if (map->matrix)
			free(map->matrix);
		free(map);
	}
}

void	clean_flood_fill(t_floodfill *flood_fill)
{
	int	i;

	if (flood_fill)
	{
		i = 0;
		if (flood_fill->map)
		{
			while (flood_fill->map[i])
			{
				free(flood_fill->map[i]);
				i++;
			}
			free(flood_fill->map);
		}
		free(flood_fill);
	}
}

void	clean_player(void *item)
{
	t_player	*player;

	if (item)
	{
		player = (t_player *)item;
		if (player->coordinates)
			free(player->coordinates);
		if (player->previous_coordinates)
			free(player->previous_coordinates);
		free(player);
	}
}
// Free MLX
void	clean_mlx(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void	clean_buffer(t_game *game, t_buffer *buffer)
{
	if (buffer->img)
	{
		mlx_destroy_image(game->mlx, buffer->img);
		buffer->img = NULL;
	}
	buffer->addr = NULL;
	buffer->bits_per_pixel = 0;
	buffer->line_length = 0;
	buffer->endian = 0;
	buffer->width = 0;
	buffer->height = 0;
}

void	clean_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_SPRITE_PLAYER)
	{
		clean_buffer(game, &game->sprites->player[i]);
		i++;
	}
	i = 0;
	while (i < TOTAL_SPRITE_COLLECTIBLE)
	{
		clean_buffer(game, &game->sprites->collectible[i]);
		i++;
	}
	i = 0;
	while (i < TOTAL_SPRITE_ENEMY)
	{
		clean_buffer(game, &game->sprites->enemy[i]);
		i++;
	}
	i = 0;
	while (i < TOTAL_SPRITE_TILES)
	{
		clean_buffer(game, &game->sprites->tiles[i]);
		i++;
	}
	i = 0;
	while (i < TOTAL_SPRITE_EXIT)
	{
		clean_buffer(game, &game->sprites->exit[i]);
		i++;
	}
	free(game->sprites);
	game->sprites = NULL;
}

void	destroy_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map);
		if (game->flood_fill)
			clean_flood_fill(game->flood_fill);
		if (game->enemies)
			ft_lstclear(&game->enemies, clean_enemy);
		if (game->collectibles)
			ft_lstclear(&game->collectibles, clean_collectible);
		if (game->mlx && game->image_buffer.img)
			mlx_destroy_image(game->mlx, game->image_buffer.img);
		if (game->sprites)
			clean_sprites(game);
		if (game->mlx)
			clean_mlx(game);
		if (game->player)
			clean_player(game->player);
		if (game->exit)
			clean_exit(game);
	}
}

void	end_game(t_game *game)
{
	if (game)
	{
		destroy_game(game);
	}
	exit(EXIT_SUCCESS);
}
