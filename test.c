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

void	testmultiple(int fd, int fd2)
{
	char	*st;
	int		i;
	int		i2;

	st = NULL;
	i = 1;
	i2 = 1;
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
}

void	test(int fd)
{
	char	*st;
	int		out;
	int		i;

	st = NULL;
	i = 1;
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd, &st);
		doprint(out, &st, i++);
	}
}


int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;

	if (argc == 1)
	{
		test(0);
	}
	else if (argc == 2 && strcmp(argv[1], "INVALID_FD") == 0)
	{
		test(42);
		test(43);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		test(fd);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		testmultiple(fd, fd2);
	}
	return (0);
}
