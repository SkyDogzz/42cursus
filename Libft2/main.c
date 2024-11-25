#include "include/libft.h" 

int main(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		loop;

	if (argc < 1)
	{
		return EXIT_FAILURE;
	}
	fd = open(argv[1], O_RDONLY);
	loop = 1;
	while((line = get_next_line(fd)))
	{
		ft_printf("loop %d: %s", loop++, line);
	}
	return EXIT_SUCCESS;
}
