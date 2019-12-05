#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char *line;
	int out = 1;
	int fd = open("main.c", O_RDONLY | O_EXCL);

	line = (char *)0x37624236487;
	while (out == 1)
	{
		out = get_next_line(fd, &line);
		printf("[OUT %i][%s]\n", out, line);
		free(line);
	}
	close(fd);
	return (0);
}
