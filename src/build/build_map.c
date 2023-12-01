/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:41:24 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/01 15:55:09 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	convert_lst_to_char(t_game *game)
{
	t_list	*lst;
	int		i;

	lst = game->map->lst_map;
	i = 0;
	game->map->height = ft_lstsize(game->map->lst_map);
	game->map->matrix = ft_calloc(game->map->height + 1, sizeof(char *));
	if (!game->map->matrix)
		error_handler("Error\nMemory allocation failed.\n", game);
	game->flood_fill->map = ft_calloc(sizeof(char *), game->map->height);
	if (!game->flood_fill->map)
		error_handler("Error\nMemory allocation failed.\n", game);
	while (lst)
	{
		game->map->matrix[i] = ft_strdup(lst->content);
		game->flood_fill->map[i] = ft_strdup(lst->content);
		if (!game->map->matrix[i] || !game->flood_fill->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
}

void	build_map(char *map_path, t_game *game)
{
	int	fd;

	check_map_extension(map_path, game);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_handler("Error\nMap file could not be opened.\n", game);
	read_map(fd, game);
	close(fd);
	game->flood_fill = ft_calloc(1, sizeof(t_floodfill));
	if (!game->flood_fill)
		error_handler("Error\nMemory allocation failed.\n", game);
	convert_lst_to_char(game);
}
