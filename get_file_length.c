
#include "libcrono.h"

off_t	get_file_length(char *file1)
{
	struct stat	st;

	if (stat(file1, &st) == -1)
		return (-1);
	return (st.st_size);
}
