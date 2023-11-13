/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 14:58:29 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	*mlx;
// void	*win;

// mlx = mlx_init();
// if (!mlx)
// {
// 	ft_putstr_fd("Error\nmlx_init() failed\n", 2);
// 	return (0);
// }
// win = mlx_new_window(mlx, 640, 480, "so_long");
// if (!win)
// {
// 	ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
// 	return (0);
// }
// mlx_loop(mlx);

int	main(int ac, char **av)
{
	// t_map	map;

	(void)av;
	if (ac == 1)
		ft_error_handler("Error\nNo map specified.\n");
	if (ac != 2)
		ft_error_handler("Error\nToo many arguments.\n");
	if (!check_path_map(av[1]))
		ft_error_handler("Error\nMap not found.\n");

	return (0);
}
