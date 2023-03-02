/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:02 by  amangold         #+#    #+#             */
/*   Updated: 2023/02/20 14:47:37 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	
	fd1 = open("tests/test.txt", 0_RDONLY);
	fd2 = open("tests/test2.txt", 0_RDONLY);
	fd3 = open("tests/test3.txt", 0_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free (line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free (line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free (line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
