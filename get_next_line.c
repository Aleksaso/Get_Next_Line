/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:54:15 by asilva-o          #+#    #+#             */
/*   Updated: 2024/03/26 15:53:26 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	get_next_line(int fd, char **line)
{
	char	buf[2];
	int		bytes_read;

	*line = malloc(1);
	(*line)[0] = '\0';
	while ((bytes_read = read(fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		if (*buf == '\n')
			return (1);
		*line = realloc(*line, strlen(*line) + 2);
		strcat(*line, buf);
	}
	return (bytes_read == 0) ? 0 : -1;
}
