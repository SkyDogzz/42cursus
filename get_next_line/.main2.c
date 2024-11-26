#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int		fd1, fd2;
	char	*line1, *line2;

	if (argc == 1)
	{
		fprintf(stderr, "Usage: %s <input_file>", argv[0]);
		return (EXIT_FAILURE);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("%s", line1);
	printf("%s", line2);

	free(line1);
	free(line2);

	return EXIT_SUCCESS;
}
