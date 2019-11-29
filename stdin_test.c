/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 09:40:33 by skorteka      #+#    #+#                 */
/*   Updated: 2019/11/25 09:40:34 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

int		main(void)
{
	char	*line;
	int		out;

	line = NULL;
	out = 1;
	while (out)
	{
		out = get_next_line(0, &line);
		printf("[OUT %i][%s]\n", out, line);
		free(line);
		line = NULL;
	}
	return (0);
}
