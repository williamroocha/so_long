/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:17 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 17:53:46 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_map *map, const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error\nFailed to open map file.\n");
	map->rows = 0;
	map->cols = 0;
	while (get_next_line(fd))
	{
		map->rows++;
		if (map->cols == 0)
			map->cols = ft_strlen(line);
		free(line);
	}
	close(fd);
	initialize_map(map, map->rows, map->cols);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd))
	{
		ft_strlcpy(map->grid[i], line, map->cols + 1);
		free(line);
		i++;
	}
	close(fd);
}
