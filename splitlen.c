
#include "libcrono.h"

int	splitlen(char **ptr)
{
	int		ind;

	ind = 0;
	while (ptr[ind])
		ind++;
	return (ind);
}
