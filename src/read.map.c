/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:16 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 19:07:32 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_map(t_game *map, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error\nCould not open map.\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (1);
}
