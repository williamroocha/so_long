/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:41:24 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/08 13:23:18 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build_map(char *map_path, t_game *game)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_handler("Error\nMap file could not be opened.\n", NULL);
	check_map_extension(map_path);
	read_map(fd, game);
	close(fd);
	game->flood_fill = ft_calloc(1, sizeof(t_floodfill));
	if (!game->flood_fill)
		error_handler("Error\nMemory alloc failed: build_map.\n", game);
	convert_lst_to_char(game);
}
