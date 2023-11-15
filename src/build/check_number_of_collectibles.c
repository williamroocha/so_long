/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_collectibles.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:48 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 12:28:15 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_number_of_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	num_collectibles;

	i = 0;
	num_collectibles = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map_arr[i][j] == 'C')
				num_collectibles++;
			j++;
		}
		i++;
	}
	return (num_collectibles);
}
