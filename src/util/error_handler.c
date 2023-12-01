/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:23 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/01 16:57:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handler(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	end_game(game);
	exit(EXIT_FAILURE);
}
