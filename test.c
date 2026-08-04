
#include "libcrono.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (strcmp(argv[1], "split") == 0 && argc == 4)
		print_split(split(argv[2], argv[3][0]));
	return (0);
}
