
#include "libcrono.h"

void	print_split(char **ptr)
{
	while (*ptr)
	{
		printf("%s\n", *ptr);
		ptr++;
	}
}
