
#include "libcrono.h"

char	*next_token(char *str, char *find)
{
	char	*strst;
	char	*result;

	strst = strstr(str, find);
	if (!strst)
		return (NULL);
	result = substr(str, 0, (size_t)(strst - str));
	strcpy(str, strst + strlen(find));
	return (result);
}
