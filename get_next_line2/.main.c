#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*buffer;

	printf("%d\n", argc);
	if (argc != 2)
	{
		fprintf(stderr, "Usage = %s filename.\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == - 1)
	{
		fprintf(stderr, "File can't be read\n");
		return (EXIT_FAILURE);
	}

	printf("%d\n", BUFFER_SIZE);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while ((buffer = get_next_line(fd)))
	{
		printf("%s", buffer);
	}
	

	return (0);
}
