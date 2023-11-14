/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:16 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/14 17:07:09 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	line_map_size(t_map *map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (map->map_arr[i] && map->map_arr[i][j])
	{
		if (map->map_arr[i][j] != '\n')
			size++;
		j++;
	}
	map->map_width = size;
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
		if (!save_line(map, line))
			break ;
	}
	line_map_size(map);
	printf("line_map_size: %d\n", map->map_width);
	close(fd);
}
