/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/30 17:49:38 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 1)
		ft_error_handler("Error\nNo map specified.\n");
	else if (ac != 2)
		ft_error_handler("Error\nToo many arguments.\n");
	else
	{
		build(av[1], &game);
		register_hook(&game);
	}
	return (0);
}

// Need make an function to free all the memory allocated.
