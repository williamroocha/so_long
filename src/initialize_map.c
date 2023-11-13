/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:11:18 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:24 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_map(t_map *map, int rows, int cols)
{
	int	i;

	map->rows = rows;
	map->cols = cols;
	map->grid = (char **)malloc(sizeof(char *) * rows);
	if (!map->grid)
		ft_error_handler("Error\nMemory allocation for the grid failed.\n");
	i = 0;
	while (i < rows)
	{
		map->grid[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map->grid[i])
			ft_error_handler("Error\nMemory allocation for the rows failed.\n");
		i++;
	}
}
