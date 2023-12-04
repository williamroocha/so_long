/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:06:26 by wiferrei          #+#    #+#             */
/*   Updated: 2023/12/04 08:47:26 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map_extension(char *path)
{
	char	*extension;

	extension = ft_strchr(path, '.');
	if (extension == NULL)
		error_handler("Error\nMap file has no extension.\n", NULL);
	if (ft_strcmp(extension, BER) != 0)
		error_handler("Error\nMap file has wrong extension.\n", NULL);
}
