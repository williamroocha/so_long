/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:19:36 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 15:04:51 by wiferrei         ###   ########.fr       */
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




// main functions
int			main(int ac, char **av);

// check map functions
int			check_path_map(char *map);
int			check_number_of_players(t_map *map);
int			check_number_of_exits(t_map *map);
int			check_number_of_collectibles(t_map *map);
int			check_map_walls(t_map *map);

void		check_map(t_map *map);

void		read_map(t_map *map, char *file_path);
void		initialize_map(t_map *map, int rows, int cols);

#endif
