/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:07 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/23 17:16:54 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// reads the content of fd
static char	*read_line( int fd, char *line)
{
	int		byte;
	char	*nextline;

	if (line == NULL)
		line = ft_calloc(1, 1);
	nextline = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (nextline == NULL)
		return (free(line), NULL);
	byte = 1;
	while (!ft_strchr(line, '\n') && byte != 0)
	{
		byte = read(fd, nextline, BUFFER_SIZE);
		if (byte < 0)
			return (free(nextline), free(line), NULL);
		nextline[byte] = '\0';
		line = ft_strjoin(line, nextline);
		if (line == NULL)
			return (free(nextline), NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (free(nextline), line);
}

// takes the line before '\n'
static char	*get_buffer(char *line)
{
	char	*nextline;
	int		i;

	i = 0;
	if (line == NULL || line[i] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	nextline = ft_calloc(i + 2, sizeof(char));
	if (nextline == NULL)
		return (free(line), NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		nextline[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		nextline[i++] = '\n';
	return (nextline);
}

// Frees the result and makes line = the file content
static char	*next_line(char *line)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	if (line == NULL || line[i] == '\0')
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == NULL)
		return (free(line), NULL);
	nextline = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	if (nextline == NULL)
		return (free(line), NULL);
	i++;
	j = 0;
	while (line[i] != '\0')
		nextline[j++] = line[i++];
	nextline[j] = '\0';
	free(line);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (line == NULL)
		return (NULL);
	nextline = get_buffer(line);
	line = next_line(line);
	return (nextline);
}
