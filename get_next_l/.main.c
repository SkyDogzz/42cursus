#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 1)
	{
		fprintf(stderr, "Usage: %s <input_file>", argv[0]);
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	int loop = 1;
	while ((line = get_next_line(fd)) && *line != 0)
	{
		// printf("%s", line);
		printf("loop %d %s", loop++, line);
	}

	return EXIT_SUCCESS;
}
