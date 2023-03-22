/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:50:42 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/22 14:53:34 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *hay, int needle)
{
	char	*str;
	int		first;

	if (!hay)
		return (NULL);
	str = (char *)hay;
	first = 0;
	while (str[first] != '\0' && str[first] != (char) needle)
		first++;
	if (str[first] == (char) needle)
		return (str + first);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (free(s1), join);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	s = str;
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*memory;
	unsigned long	i;

	i = 0;
	memory = malloc(count * size);
	if (count && (count * size) / count != size)
		return (NULL);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}
