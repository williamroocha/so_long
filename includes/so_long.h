/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:19:36 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 09:02:51 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "constants.h"
# include "structs.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// Main function:
int			main(int ac, char **av);

// Utils functions:
int			check_map_characters(t_game *game);
char		*make_path(char *map_path);
void		check_map_extension(char *map_path);
int			check_map_walls(t_game *game);
void		check_map(t_game *game);
void		fill(int y, int x, t_game *game, char to_fill);
int			flood_fill(t_game *game);
int			is_right_wall(t_game *game, t_coord *coord);
int			is_left_wall(t_game *game, t_coord *coord);
int			is_top_wall(t_game *game, t_coord *coord);
int			is_down_wall(t_game *game, t_coord *coord);
int			is_exit(t_game *game, t_coord *coord);
void		move_right(t_game *game, t_coord *coord, t_coord *last_coord,
				int is_player);
void		move_left(t_game *game, t_coord *coord, t_coord *last_coord,
				int is_player);
void		move_up(t_game *game, t_coord *coord, t_coord *last_coord,
				int is_player);
void		move_down(t_game *game, t_coord *coord, t_coord *last_coord,
				int is_player);
void		move_enemy(t_game *game);
void		dead_player(t_game *game);
void		clean_lst(void *item);
void		clean_collectible(void *item);
void		clean_enemy(void *item);
void		clean_player(void *item);
void		clean_exit(t_game *game);
void		clean_map(t_map *map);
void		clean_flood_fill(t_floodfill *flood_fill);
void		clean_sprites_player(t_game *game);
void		clean_sprites_collectible(t_game *game);
void		clean_sprites_enemies(t_game *game);
void		clean_sprites_tiles(t_game *game);
void		clean_sprites(t_game *game);
void		clean_sprites_exit(t_game *game);
void		clean_buffer(t_game *game, t_buffer *buffer);
void		clean_mlx(t_game *game);
void		destroy_game(t_game *game);
void		end_game(t_game *game);
void		finish_game(t_game *game);
void		error_handler(char *msg, t_game *game);
void		convert_lst_to_char(t_game *game);

// Build functions:
void		build_map(char *map_path, t_game *game);
void		read_map(int fd, t_game *game);
t_coord		*build_coordinates(t_game *game, int x, int y);
void		build_game(t_game *game);
void		build_characters(t_game *game);
void		build_player(t_game *game, int x, int y);
void		build_enemy(t_game *game, int x, int y);
void		build_collectible(t_game *game, int x, int y);
void		build_exit(t_game *game, int x, int y);
void		build_mlx_itens(t_game *game);
void		build_sprites(t_game *game);
void		build(char *map_path, t_game *game);

// Draw functions:
void		draw(int x, int y, t_buffer *sprite, t_game *game);
int			get_pixel_color(t_buffer *sprite, int x, int y);
void		put_pixel(t_buffer *img, int x, int y, int color);
void		draw_walls(t_game *game, int x, int y);
void		draw_path(t_game *game, int x, int y);
void		draw_background(t_game *game);
void		get_item(t_game *game);
t_buffer	*get_collectible_sprite(t_collectible *collectible, t_game *game);
void		draw_collectible(t_game *game);
t_buffer	*get_enemy_sprite(t_enemy *enemy, t_game *game);
void		draw_enemy(t_game *game);
t_buffer	*get_exit_sprite(t_game *game);
void		draw_exit(t_game *game);
void		player_walk_sprite_left(t_game *game);
void		player_walk_sprite_right(t_game *game);
void		player_walk_sprite_down(t_game *game);
void		player_walk_sprite_up(t_game *game);
int			player_walk_sprite(t_game *game);
void		draw_count_steps(t_game *game);
t_buffer	*get_player_sprite(t_game *game);
t_buffer	*get_player_sprite(t_game *game);
void		draw_count_steps(t_game *game);
void		draw_player(t_game *game);

// Hook functions:
int			closing_game(t_game *game);
int			keypress(int keycode, t_game *game);
int			loop(t_game *game);
void		register_hook(t_game *game);

// test functions:
void		free_game_memory(t_game *game);
#endif
