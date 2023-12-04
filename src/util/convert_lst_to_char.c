/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lst_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:42:21 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/04 09:19:58 by wiferrei         ###   ########.fr       */
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
		error_handler("Error\nMemory alloc: convert_lst_to_char.\n", game);
	game->flood_fill->map = ft_calloc(sizeof(char *), game->map->height);
	if (!game->flood_fill->map)
		error_handler("Error\nMemory alloc: convert_lst_to_char.\n", game);
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
