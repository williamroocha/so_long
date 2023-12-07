/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:35:34 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/07 08:40:13 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clean_flood_fill(t_floodfill *flood_fill)
{
	int	i;

	if (flood_fill)
	{
		i = 0;
		if (flood_fill->map)
		{
			while (flood_fill->map[i])
			{
				free(flood_fill->map[i]);
				i++;
			}
			free(flood_fill->map);
		}
		free(flood_fill);
	}
}

void	clean_map(t_map *map)
{
	int	i;

	if (map)
	{
		i = 0;
		if (map->height)
		{
			while (i < map->height)
			{
				if (map->matrix[i])
					free(map->matrix[i]);
				i++;
			}
		}
		if (map->lst_map)
			ft_lstclear(&map->lst_map, clean_lst);
		if (map->matrix)
			free(map->matrix);
		free(map);
	}
}
