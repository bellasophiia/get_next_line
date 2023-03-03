/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:07 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/03 19:13:46 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ich gehe durch die Line und suche nach dem '\n' char
// wenn ich den gefunden habe, dann allociere ich mit malloc genug speicherplatz
// für den String bis dahin und dann schreib ich das wieder in den Buffer rein


char	*read_line(char *line)
{
	int		i;
	int		byte;
	char	*nextline;

// check if the line is existing
	if (!line || line[0])
		return (NULL);
		// goes through the line and looks for '\n'
	while (line[i] && line[i] != '\n')
		i++;
		// allocates the BUFFER for the len of nextline with malloc
	nextline = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	byte = 1;
	// looks with strchr if there is the '\n' and that byte is not 0
	while (!ft_strchr(line, '\n' && byte != 0))
	{
		// reads the nextline from the fd into the nextline
		byte = read(fd, nextline, BUFFER_SIZE)
		if (byte < 0)
		{
			free(nextline);
			return (NULL);
		}
		// 0 to end for leaks
		nextline[byte] = '\0'
		line = ft_strjoin(line, nextline);
	}
	free(nextline);
	return (line);
}

char	*get_line(char *line)
{
	char	*nextline;
	int		i;

	i = 0;
	if (!line || line[i] == '\0')
		return (NULL);
	while (nextline[i] || nextline[i] != '\n')
	i++;
	nextline = malloc(BUFFER_SIZE + 1 ) * sizeof(char);
	// (ft_strlen(line)i + 2),
	i = 0;
	// line gets written into nextline until i = '\n'
	while (line [i] && line[i] != '\n')
	{
		nextline[i] = line[i];
		i++;
	}
	// if there is '\n' then the '\n' gets appended to the str nextline 
	if (line[i] && line[i] == '\n')
	nextline[i++] = '\n';
	return (nextline);
}

char *next_line(char *line)
{
	int		i;
	int		j;
	char	*nextline;

	if (!line || line[i] == '\0')
		return (NULL);
	while (line[i] || line != '\n')
		i++;
	if (!line)
		free(line);
		return(NULL);
	line = malloc(BUFFER_SIZE + 1 ) * sizeof(char);
	i++;
	j = 0;
	while (line[i])
		line[i++] = nextline[j++];
		free (nextline);
		return (line);
}

char	get_next_line(int fd)
{
	static char	nextline;
	char		line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	nextline = read_line(line);
	if (!line)
		return (NULL);
	line = get_line(line);
	nextline = next_line(line);
	return (nextline);
}

