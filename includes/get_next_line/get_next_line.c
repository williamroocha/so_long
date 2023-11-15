/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:05:42 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/15 16:26:49 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin_gnl(0, buffer);
	if (ft_check_newline(buffer))
		return (line);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	while (bytes)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (ft_check_newline(buffer))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
