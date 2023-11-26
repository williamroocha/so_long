/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:41:16 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/26 09:29:18 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(int fd, t_game *game)
{
	char	*line;

	line = NULL;
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->map->width == 0)
			game->map->width = ft_strlen_nl(line);
		else if (game->map->width != (int)ft_strlen_nl(line))
			ft_error_handler("Error\nInvalid map, wrong size.\n");
		if (game->map->lst_map == NULL)
			game->map->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&game->map->lst_map, ft_lstnew(line));
	}
}
