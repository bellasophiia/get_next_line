/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:50:42 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/03 19:10:22 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *hay, int needle)
{
	char	*str;
	int		first;

	str = (char *)hay;
	first = 0;
	while (str[first] != '\0' && str[first] != (char) needle)
		first++;
	if (str[first] == (char) needle)
		return (str + first);
	return (NULL);
}

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

size_t	strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != 0 && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	int		i;

	duplicate = (char *) malloc (sizeof (char) * ft_strlen(s1) +1);
	if (duplicate == NULL)
		return ((char *) NULL);
	i = 0;
	while (*s1)
	{
		duplicate[i] = *s1;
		i++;
		s1++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*memory;
	unsigned long	i;

	i = 0;
	if (count && (count * size) / count != size)
		return (NULL);
	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	while (i < size * count)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
