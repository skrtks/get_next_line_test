#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	// char *line;
	// int out = 1;
	// int fd;
	// int i = 0;
	// while (i < 100)
	// {
	// 	out = 1;
	// 	fd = open("../get_next_line/get_next_line.c", O_RDONLY | O_EXCL);

	// 	while (out == 1)
	// 	{
	// 		out = get_next_line(fd, &line);
	// 		printf("[OUT %i][%s]\n", out, line);
	// 		free(line);
	// 	}
	// 	close(fd);
	// 	i++;
	// }

	char *line;
	int out = 1;
	int fd = open("../get_next_line/get_next_line.c", O_RDONLY | O_EXCL);

	while (out == 1)
	{
		out = get_next_line(fd, &line);
		printf("[OUT %i][%s]\n", out, line);
		free(line);
	}
	close(fd);

	// char *line1;
	// out = 1;
	// fd = open("../get_next_line/get_next_line.c", O_RDONLY | O_EXCL);

	// while (out == 1)
	// {
	// 	out = get_next_line(fd, &line1);
	// 	printf("[OUT %i][%s]\n", out, line1);
	// 	free(line1);
	// }
	// close(fd);

	// char *line2;
	// out = 1;
	// fd = open("../get_next_line/get_next_line.c", O_RDONLY | O_EXCL);

	// while (out == 1)
	// {
	// 	out = get_next_line(fd, &line2);
	// 	printf("[OUT %i][%s]\n", out, line2);
	// 	free(line2);
	// }
	// close(fd);


	return (0);
}
