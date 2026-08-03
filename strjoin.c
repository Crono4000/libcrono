
#include "libcrono.h"

char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index1;
	int		index2;

	str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1])
	{
		str[index1] = s1[index1];
		index1++;
	}
	while (s2[index2])
	{
		str[index1 + index2] = s2[index2];
		index2++;
	}
	str[index1 + index2] = '\0';
	return (str);
}
