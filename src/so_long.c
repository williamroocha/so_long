/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/14 16:02:52 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		printf("%s\n", map->map_arr[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac == 1)
		ft_error_handler("Error\nNo map specified.\n");
	else if (ac != 2)
		ft_error_handler("Error\nToo many arguments.\n");
	map = ft_calloc(1, sizeof(t_map));
	read_map(map, av[1]);
	check_map(map);
	print_map(map);
	return (0);
}
