#include "../get_next_line/get_next_line.h"

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char *line;

	int fd = open("text.txt", O_RDONLY | O_EXCL);

	if (fd == -1)
		printf("error reading file\n");

	line = NULL;
	int out;
	out = 1;
	while (out)
	{
		out = get_next_line(fd, &line);
		printf("[OUT %i][%s]\n", out, line);
		free(line);
		line = NULL;
	}

	close(fd);

	return (0);
}
