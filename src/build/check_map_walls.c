/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:28:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 14:54:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_map_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (i == 0 || i == map->map_height - 1)
			{
				if (map->map_arr[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == map->map_width - 1)
			{
				if (map->map_arr[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
