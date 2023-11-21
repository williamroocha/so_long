/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:19:36 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/21 16:34:26 by wiferrei         ###   ########.fr       */
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
# include <unistd.h>

// main functions
int		main(int ac, char **av);

void	build(char *map_path, t_game *game);
void	build_game(t_game *game);
t_coord	*build_coordinates(t_game *game, int x, int y);
void	build_player(t_game *game, int x, int y);
void	build_enemy(t_game *game, int x, int y);
void	build_collectible(t_game *game, int x, int y);
void	build_exit(t_game *game, int x, int y);
void	build_map(char *map_path, t_game *game);
void	read_map(int fd, t_game *game);
void	build_characters(t_game *game);
void	build_mlx_itens(t_game *game);
void	build_sprites(t_game *game);

void	register_hook(t_game *game);

// Checker functions
void	check_map_extension(char *map_path);
int		check_map_characters(t_game *game);
int		check_map_walls(t_game *game);
void	check_map(t_game *game);

// clean functions
void	clean_lst(void *item);
void	clean_collectible(void *item);
void	clean_enemy(void *item);
void	destroy_game(t_game *game);
void	end_game(t_game *game);

// Collision and direction functions
int		is_right_wall(t_game *game, t_coord *coord);
int		is_left_wall(t_game *game, t_coord *coord);
int		is_top_wall(t_game *game, t_coord *coord);
int		is_down_wall(t_game *game, t_coord *coord);

void	move_right(t_game *game, t_coord *coord, t_coord *last_coord,
			int is_player);
void	move_left(t_game *game, t_coord *coord, t_coord *last_coord,
			int is_player);
void	move_up(t_game *game, t_coord *coord, t_coord *last_coord,
			int is_player);
void	move_down(t_game *game, t_coord *coord, t_coord *last_coord,
			int is_player);

// Draw functions

void	get_item(t_game *game);

void	finish_game(t_game *game);

// Hook functions
int		closing_game(t_game *game);
int		keypress(int keycode, t_game *game);
void	register_hook(t_game *game);

#endif
