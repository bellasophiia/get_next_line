/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  amangold < amangold@student.42heilbron    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:26:37 by  amangold         #+#    #+#             */
/*   Updated: 2023/03/22 16:01:47 by  amangold        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*solution;
	fd = open("test.txt", O_RDONLY);

	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free (solution);
	close (fd);
	return (0);
}
