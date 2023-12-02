/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/02 14:40:40 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 1)
		ft_putstr_fd("Error\nNo map specified.\n", 1);
	else if (ac != 2)
		ft_putstr_fd("Error\nToo many arguments.\n", 1);
	else
	{
		build(av[1], &game);
		register_hook(&game);
	}
	return (0);
}
