/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_players.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:22:17 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 12:22:56 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_number_of_players(t_map *map)
{
	int	i;
	int	j;
	int	num_players;

	i = 0;
	num_players = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map_arr[i][j] == 'P')
				num_players++;
			j++;
		}
		i++;
	}
	return (num_players);
}