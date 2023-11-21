/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:15:35 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 12:11:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map
{
	char		**matrix;
	t_list		*lst_map;
	int			height;
	int			width;
}				t_map;

typedef struct s_floodfill
{
	char		**map;
	int			number_collectibles;
	int			number_exits;
	int			x;
	int			y;
}				t_floodfill;

typedef struct s_player
{
	int			animation;
	int			steps;
	t_coord		*coordinates;
	t_coord		*previous_coordinates;
}				t_player;

typedef struct s_exit
{
	t_coord		*coordinates;
}				t_exit;

typedef struct s_buffer
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_buffer;

typedef struct s_sprites
{
	t_buffer	player[TOTAL_SPRITE_PLAYER];
	t_buffer	collectible[TOTAL_SPRITE_COLLECTIBLE];
	t_buffer	enemy[TOTAL_SPRITE_ENEMY];
	t_buffer	tiles[TOTAL_SPRITE_TILES];
	t_buffer	exit[TOTAL_SPRITE_EXIT];

}				t_sprites;

typedef struct s_enemy
{
	int			animation;
	int			animation_position;
	int			last_movement;
	t_coord		*coordinates;
	t_coord		*previous_coordinates;
}				t_enemy;

typedef struct s_collectible
{
	int			animation;
	int			animation_position;
	int			collected;
	int			visible;
	t_coord		*coordinates;
}				t_collectible;

typedef struct s_game
{
	t_map		*map;
	t_floodfill	*flood_fill;
	t_list		*enemies;
	t_list		*collectibles;
	t_player	*player;
	t_exit		*exit;
	t_sprites	*sprites;
	void		*mlx;
	void		*window;
	t_buffer	image_buffer;
	int			exit_animation;
	int			exit_animation_pos;
	int			nbr_collectibles;
	int			nbr_enemies;
	int			nbr_player;
	int			nbr_exit;
}				t_game;

#endif