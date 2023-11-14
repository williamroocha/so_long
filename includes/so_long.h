/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:19:36 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/14 16:02:22 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map_data
{
	char	**map_arr;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		num_colect;
	int		num_players;
	int		num_exit;
	void	*g_player;
	void	*g_wall;
	void	*g_player_up;
	void	*g_player_left;
	void	*g_player_down;
	void	*g_player_right;
	void	*g_floor;
	void	*g_collect;
	void	*g_exit;
	void	*g_open_exit;
	void	*mlx;
	void	*mlx_win;
}			t_map;

int				main(int ac, char **av);
int				check_path_map(char *map);
void			read_map(t_map *map, char *file_path);
void			check_map(t_map *map);
void			initialize_map(t_map *map, int rows, int cols);

#endif
