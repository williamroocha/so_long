/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:57:19 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/06 08:49:03 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	build(char *map_path, t_game *game)
{
	build_game(game);
	build_map(map_path, game);
	build_characters(game);
	check_map(game);
	build_mlx_itens(game);
	build_sprites(game);
}
