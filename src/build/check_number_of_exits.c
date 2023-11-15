/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_exits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:25:24 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 12:26:01 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_number_of_exits(t_map *map)
{
	int	i;
	int	j;
	int	num_exits;

	i = 0;
	num_exits = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map_arr[i][j] == 'E')
				num_exits++;
			j++;
		}
		i++;
	}
	return (num_exits);
}