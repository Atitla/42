#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *line;

	fd = open("tralala", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (line == NULL)
			break;
	}

}
