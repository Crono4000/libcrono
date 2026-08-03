
#include "libcrono.h"

char	*substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;
	unsigned int	llen;

	llen = strlen(s);
	if (llen - start < len)
		len = llen - start;
	if (start >= llen)
		len = 0;
	index = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (start + index < llen && index < len)
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
