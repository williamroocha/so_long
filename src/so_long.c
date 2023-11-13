/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 17:43:48 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	(void)av;
	if (ac == 1)
		ft_error_handler("Error\nNo map specified.\n");
	if (ac != 2)
		ft_error_handler("Error\nToo many arguments.\n");
	if (!check_path_map(av[1]))
		ft_error_handler("Error\nMap not found.\n");

	fill_map(&map, av[1]);



	return (0);
}
