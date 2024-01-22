#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
//	write(fd, NULL, 0);
	str = get_next_line(fd);
	close(fd);
	str = get_next_line(fd);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}

