/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:07 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/02 16:36:19 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ich gehe durch die Line und suche nach dem '\n' char
wenn ich den gefunden habe, dann allociere ich mit malloc genug speicherplatz
für den String bis dahin und dann schreib ich das wieder in den Buffer rein


char	*read_line(char *line)
{
	int		i;
	int		byte;
	char	*nextline;

	if (!line || line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	nextline = malloc(BUFFER_SIZE + 1) * sizeof(char);
	byte = 1;
	while (!ft_strchr(str, '\n' && byte != 0))
	{
		byte = read(fd, nextline, BUFFER_SIZE)
		if (byte < 0)
		{
			free(nextline);
			return(NULL);
		}
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
	nextline = malloc (ft_strlen(line) - i + 2), sizeof(char);
	i = 0;
	while (line [i] && line[i] != '\n')
	{
		nextline[i] = line[i]
		i++;
	}
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
	
	
}

char	get_next_line(int fd)
{

}