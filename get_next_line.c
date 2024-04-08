/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:25:20 by asilva-o          #+#    #+#             */
/*   Updated: 2024/04/08 09:55:40 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* */
char	*concatena_linea(char *linea1, char *linea2)
{
	char	*concatenar;

	if (!linea1)
	{
		linea1 = malloc(1);
		if (!linea1)
		{
			return (NULL);
		}
		linea1[0] = '\0';
	}
	concatenar = ft_strjoin(linea1, linea2);
	free(linea1);
	return (concatenar);
}

/* */
char	*extraer_linea(char *totake_lineas)
{
	char	*linea;
	size_t	i;

	if (!totake_lineas || !*totake_lineas)
		return (NULL);
	i = 0;
	while (totake_lineas[i] != '\n' && totake_lineas[i] != '\0')
		i++;
	if (totake_lineas[i] == '\n')
		i++;
	linea = malloc(sizeof(char) * (i + 1));
	if (!linea)
		return (NULL);
	i = 0;
	while (totake_lineas[i] != '\n' && totake_lineas[i] != '\0')
	{
		linea[i] = totake_lineas[i];
		i++;
	}
	if (totake_lineas[i] == '\n')
		linea[i++] = '\n';
	linea[i] = '\0';
	return (linea);
}

/* */
char	*actualiza_totake(char *totake_lineas)
{
	char	*nextlinea;
	char	*resto;
	int		i;

	i = 0;
	resto = ft_strchr(totake_lineas, '\n');
	if (!resto)
	{
		free(totake_lineas);
		return (NULL);
	}
	resto++;
	nextlinea = malloc(sizeof(char) * (ft_strlen(resto) + 1));
	if (!nextlinea)
		return (NULL);
	while (*resto != '\0')
	{
		nextlinea[i] = *resto;
		i++;
		resto++;
	}
	nextlinea[i] = '\0';
	free(totake_lineas);
	return (nextlinea);
}

/* */
char	*get_next_line(int fd)
{
	static char	*totake_lineas;
	char		nueva[BUFFER_SIZE + 1];
	char		*linea;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, nueva, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(totake_lineas), totake_lineas = NULL, NULL);
		nueva[bytes_read] = '\0';
		totake_lineas = concatena_linea(totake_lineas, nueva);
		if (!totake_lineas)
			return (NULL);
		if (ft_strchr(totake_lineas, '\n'))
			break ;
	}
	linea = extraer_linea(totake_lineas);
	totake_lineas = actualiza_totake(totake_lineas);
	return (linea);
}

/*int	main(void)
{
	int		fd;
	char	*linea;
	fd = open("texto.txt", O_RDONLY);
	linea = get_next_line(fd);
	printf("%s", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	free(linea);…
	linea = get_next_line(fd);
	printf("%s", linea);
	free(linea);
	return (0);
}*/
