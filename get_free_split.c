
#include "libcrono.h"

// returns the the char* from a char** NULL terminated and frees the rest
char	*get_free_split(char **ptr, int indice)
{
	int		ind;
	char	*result;

	result = NULL;
	ind = 0;
	while (ptr[ind])
	{
		if (ind != indice)
			free(ptr[ind]);
		else
			result = ptr[ind];
		ind++;
	}
	free(ptr);
	return (result);
}
