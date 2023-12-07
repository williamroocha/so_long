/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:35:34 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 09:44:23 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_flood_fill(t_game *game)
{
	int	i;

	if (game->flood_fill)
	{
		i = 0;
		if (game->flood_fill->map)
		{
			while (game->flood_fill->map[i])
			{
				free(game->flood_fill->map[i]);
				i++;
			}
			free(game->flood_fill->map);
		}
		free(game->flood_fill);
		game->flood_fill = NULL;
	}
}

void	clean_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		if (game->map->height)
		{
			while (i < game->map->height)
			{
				if (game->map->matrix[i])
					free(game->map->matrix[i]);
				i++;
			}
		}
		if (game->map->lst_map)
			ft_lstclear(&game->map->lst_map, clean_lst);
		if (game->map->matrix)
			free(game->map->matrix);
		free(game->map);
		game->map = NULL;
	}
}
