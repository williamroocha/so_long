/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/10/18 09:29:39 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr_fd("Error\nmlx_init() failed\n", 2);
		return (0);
	}
	win = mlx_new_window(mlx, 640, 480, "so_long");
	if (!win)
	{
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
		return (0);
	}
	mlx_loop(mlx);
}
