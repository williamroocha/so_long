/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:19:36 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 18:33:22 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "constants.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

typedef struct s_game
{
	t_map		*map;
	t_floodfill	*flood_fill;
	t_list		*enemies;
	t_list		*collectibles;
	// t_player	*player;
	// t_exit		*exit;
	// t_sprites	*sprites;
	void		*mlx;
	void		*window;
	// t_buffer	image_buffer;
	int			exit_animation;
	int			exit_animation_pos;
	int			total_collectibles;
	int			nbr_player;
	int			nbr_exit;
}				t_game;

// main functions
int				main(int ac, char **av);

void			build(char *map_path, t_game *game);
void			build_game(t_game *game);
void			build_map(char *map_path, t_game *game);
void			read_map(int fd, t_game *game);

// Checker functions
void			check_map_extension(char *map_path);
int				check_map_characters(t_game *game);
int				check_map_walls(t_game *game);
void			check_map(t_game *game);

// int			check_path_map(char *map);
// int			check_number_of_players(t_map *map);
// int			check_number_of_exits(t_map *map);
// int			check_number_of_collectibles(t_map *map);

#endif
