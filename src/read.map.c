/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:16 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 13:34:46 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	line_map_size(t_map *map)
{
	int		i;
	size_t	max_width;
	size_t	line_length;

	i = 0;
	max_width = 0;
	while (map->map_arr[i])
	{
		line_length = ft_strlen(map->map_arr[i]);
		if (line_length > max_width)
			max_width = line_length;
		i++;
	}
	map->map_width = max_width;
}

int	save_line(t_map *map, char *line)
{
	char	**tmp_map;
	int		i;

	if (!line)
		return (0);
	i = 0;
	map->map_height++;
	tmp_map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (!tmp_map)
		return (0);
	tmp_map[map->map_height] = NULL;
	while (i < map->map_height - 1)
	{
		tmp_map[i] = map->map_arr[i];
		i++;
	}
	tmp_map[i] = ft_strdup(line);
	if (map->map_arr)
		free(map->map_arr);
	map->map_arr = tmp_map;
	return (1);
}

void	read_map(t_map *map, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error\nMap not found.\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		save_line(map, line);
		free(line);
	}
	line_map_size(map);
	close(fd);
}
