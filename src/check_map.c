/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:41:52 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/14 17:24:55 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	printf("num_players: %d\n", num_players);
	return (num_players);
}

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
	printf("num_exits: %d\n", num_exits);
	return (num_exits);
}

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
	printf("num_collectibles: %d\n", num_collectibles);
	return (num_collectibles);
}

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

int	check_if_rectangular(t_map *map)
{
	int i = 1; // Start from the second line
	while (i < map->map_height)
	{
		if (i == map->map_height - 1)
		{
			if (ft_strlen(map->map_arr[i]) != (size_t)map->map_width)
			{
				printf("ft_strlen(map->map_arr[i]): %zu\n",
					ft_strlen(map->map_arr[i]));
				printf("map->map_width: %d\n", map->map_width);
				return (0);
			}
		}
		else
		{
			if (ft_strlen(map->map_arr[i]) != (size_t)map->map_width - 1)
			{
				printf("ft_strlen(map->map_arr[i]): %zu\n",
					ft_strlen(map->map_arr[i]));
				printf("map->map_width: %d\n", map->map_width);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

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
	if (!check_if_rectangular(map))
		ft_error_handler("Error\nMap is not rectangular.\n");
}
