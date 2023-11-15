/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:41:52 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 14:59:32 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(t_map *map)
{
	if (check_number_of_players(map) != 1)
		ft_error_handler("Error\nInvalid number of players.\n");
	if (check_number_of_exits(map) != 1)
		ft_error_handler("Error\nInvalid number of exits.\n");
	if (check_number_of_collectibles(map) == 0)
		ft_error_handler("Error\nInvalid number of collectibles.\n");
	if (!check_map_walls(map))
		ft_error_handler("Error\nInvalid  walls in the map.\n");
}
