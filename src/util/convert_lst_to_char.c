/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lst_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:42:21 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/06 08:28:07 by wiferrei         ###   ########.fr       */
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
	game->flood_fill->map = ft_calloc(game->map->height + 1, sizeof(char *));
	if (!game->map->matrix || !game->flood_fill->map)
		error_handler("Error\nMemory alloc: convert_lst_to_char.\n", game);
	while (lst)
	{
		game->map->matrix[i] = ft_strdup(lst->content);
		game->flood_fill->map[i] = ft_strdup(lst->content);
		if (!game->map->matrix[i] || !game->flood_fill->map[i])
			error_handler("Error\nMemory alloc: convert_lst_to_char.\n", game);
		i++;
		lst = lst->next;
	}
	game->map->matrix[i] = NULL;
	game->flood_fill->map[i] = NULL;
}
