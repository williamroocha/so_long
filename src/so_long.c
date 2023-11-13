/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:33 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 18:46:09 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_error_handler("Error\nNo map specified.\n");
	if (ac != 2)
		ft_error_handler("Error\nToo many arguments.\n");
	if (!check_path_map(av[1]))
		ft_error_handler("Error\nMap not found.\n");
	return (0);
}
