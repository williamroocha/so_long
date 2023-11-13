/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:05:42 by wiferrei          #+#    #+#             */
/*   Updated: 2023/11/13 16:04:23 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ln;
	static char	buffer[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = -1;
		while (buffer[++i])
			buffer[i] = 0;
		return (NULL);
	}
	ln = NULL;
	while (i > 0)
	{
		if (!buffer[0])
			i = read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
			ln = gnl_strjoin(ln, buffer);
		if (ft_find_nl(buffer) > 0)
			break ;
	}
	return (ln);
}
