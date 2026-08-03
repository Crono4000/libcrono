
#include "libcrono.h"

char	*get_file_name(char *path)
{
	char	**result;
	int		size;

	result = split(path, '/');
	size = splitlen(result);
	return (get_free_split(result, size - 1));
}
