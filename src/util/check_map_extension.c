/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:06:26 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 17:25:16 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

char	*make_path(char *map_path)
{
	int		length;
	char	*path;
	int		i;

	if (map_path == NULL || map_path[0] == '\0')
		return (NULL);
	length = 0;
	while (map_path[length + 1] != '\0')
		length++;
	path = (char *)malloc(length + 1);
	if (path == NULL)
		return (NULL);
	i = 1;
	while (i <= length)
	{
		path[i - 1] = map_path[i];
		i++;
	}
	path[length] = '\0';
	return (path);
}

void	check_map_extension(char *map_path)
{
	char	*extension;
	char	*path;

	path = make_path(map_path);
	extension = ft_strchr(path, '.');
	if (extension == NULL)
		ft_error_handler("Error\nMap file has no extension.\n");
	if (ft_strcmp(extension, BER) != 0)
		ft_error_handler("Error\nMap file has wrong extension.\n");
}
