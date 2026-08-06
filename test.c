
#include "libcrono.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		result;
	int		fd;

	if (argc < 2)
		return (1);
	if (strcmp(argv[1], "split") == 0 && argc == 4)
		print_split(split(argv[2], argv[3][0]));
	if (strcmp(argv[1], "cat") == 0 && argc == 3)
	{
		fd = open(argv[2], O_RDONLY);
		while(line = get_next_line(fd))
			printf("%s", line);
		close(fd);
	}
	if (strcmp(argv[1], "get_next_part") == 0 && argc == 4)
	{
		fd = open(argv[2], O_RDONLY);
		while(line = get_next_part(fd, argv[3]))
			printf("%s%%\n", line);
		close(fd);
	}
	if (strcmp(argv[1], "special_strjoin") == 0 && argc == 5)
	{
		line = special_strjoin(argv[2], argv[3], argv[4], 0);
		printf("%s\n", line);
	}
	if (strcmp(argv[1], "special_strlen") == 0 && argc == 4)
	{
		result = special_strlen(argv[2], argv[3]);
		printf("%d\n", result);
	}
	if (strcmp(argv[1], "trimbuffer") == 0 && argc == 4)
	{
		line = strdup(argv[2]);
		trimbuffer(line, argv[3]);
		printf("%s\n", line);
	}
	return (0);
}
